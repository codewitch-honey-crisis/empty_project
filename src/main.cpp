#if __has_include(<Arduino.h>)
#include <Arduino.h>
#include <display.hpp>
#else
#include <stdio.h>
#include <stdint.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
extern "C" void app_main();
#endif

#ifdef M5STACK_CORE2
static m5core2_power power;
#endif

#ifdef ARDUINO
void setup() {
    Serial.begin(115200);
    // enable the power pins, as necessary
#ifdef T_DISPLAY_S3
    pinMode(15, OUTPUT); 
    digitalWrite(15, HIGH);
#elif defined(S3_T_QT)
    pinMode(4, OUTPUT); 
    digitalWrite(4, HIGH);
#endif
#ifdef M5STACK_CORE2
    power.initialize();
#endif
    // put your init code here
}
void loop() {
    // insert loop code here
}
#else
static void loop_task(void* state) {
    while(true) {
        // insert loop code here
        vTaskDelay(5);
    }
}
void app_main() {
#ifdef T_DISPLAY_S3
    gpio_set_direction((gpio_num_t)15,GPIO_MODE_OUTPUT);
    gpio_set_level((gpio_num_t)15,1);
#elif defined(S3_T_QT)
    gpio_set_direction((gpio_num_t)4,GPIO_MODE_OUTPUT);
    gpio_set_level((gpio_num_t)4,1);
#endif
#ifdef M5STACK_CORE2
    power.initialize();
#endif
    // put your init code here
    TaskHandle_t htask = nullptr;
    xTaskCreate(loop_task,"loop_task",5000,nullptr,uxTaskPriorityGet(nullptr),&htask);
    if(htask==nullptr) {
        printf("Unable to create loop task\n");
    }
    vTaskSuspend(nullptr);
}
#endif