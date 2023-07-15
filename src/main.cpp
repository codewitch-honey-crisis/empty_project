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
#include <ui.hpp>
#ifdef HAS_DISPLAY
using namespace gfx;
using namespace uix;
#endif
static void common_init() {
#ifdef HAS_POWER
    power_initialize();
#endif
#ifdef HAS_BUTTONS
    buttons_initialize();
#ifdef HAS_DISPLAY
    buttons[0].on_pressed_changed([](bool pressed, void* state){
        if(pressed) {
            spoint16 tmp = spoint16::zero();
            hello_button.on_touch(1,&tmp);
        } else {
            hello_button.on_release();
        }
    });
#endif
#endif
#ifdef HAS_TOUCH
    touch_initialize();
#endif

#ifdef HAS_DISPLAY
    display_initialize();
    main_screen_initialize();
    display_screen(main_screen);
#ifdef HAS_TOUCH
    touch_activate_screen();
#endif

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