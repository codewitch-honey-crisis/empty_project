#if __has_include(<Arduino.h>)
#include <Arduino.h>
#else
#include <stdio.h>
#include <stdint.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
extern "C" void app_main();
#endif
#include <display.hpp>
#include <input.hpp>
#include <power.hpp>

static void common_init() {
#ifdef HAS_POWER
    power_initialize();
#endif
#ifdef HAS_DISPLAY
    display_initialize();
#endif
#ifdef HAS_BUTTONS
    buttons_initialize();
#endif
#ifdef HAS_TOUCH
    touch_initialize();
#endif
}

static void common_loop() {
#ifdef HAS_DISPLAY
    display_update();
#endif
#ifdef HAS_BUTTONS
    buttons_update();
#endif
}

#ifdef ARDUINO
void setup() {
    Serial.begin(115200);
    common_init();
}
void loop() {
    common_loop();
}
#else
static void loop_task(void* state) {
    while(true) {
        common_loop();
        vTaskDelay(5);
    }
}
void app_main() {
    common_init();
    TaskHandle_t htask = nullptr;
    xTaskCreate(loop_task,"loop_task",5000,nullptr,uxTaskPriorityGet(nullptr),&htask);
    if(htask==nullptr) {
        printf("Unable to create loop task\n");
    }
    vTaskSuspend(nullptr);
}
#endif