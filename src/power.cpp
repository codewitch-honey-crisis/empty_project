#include <power.hpp>
#if __has_include(<Arduino.h>)
#include <Arduino.h>
#else
#include <stdio.h>
#include <stdint.h>
#include <driver/gpio.h>
#endif

#ifdef T_DISPLAY_S3
void power_initialize() {
#ifdef ARDUINO
    pinMode(15, OUTPUT); 
    digitalWrite(15, HIGH);
#else
    gpio_set_direction((gpio_num_t)15,GPIO_MODE_OUTPUT);
    gpio_set_level((gpio_num_t)15,1);
#endif
}
#endif

#ifdef M5STACK_CORE2
power_t power;
void power_initialize() {
    power.initialize(true);
}
#endif

#ifdef S3_T_QT
void power_initialize() {
#ifdef ARDUINO
    pinMode(4, OUTPUT); 
    digitalWrite(4, HIGH);
#else
    gpio_set_direction((gpio_num_t)4,GPIO_MODE_OUTPUT);
    gpio_set_level((gpio_num_t)4,1);
#endif
}
#endif
