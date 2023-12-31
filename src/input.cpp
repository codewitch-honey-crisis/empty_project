#include <input.hpp>

#ifdef ESP_DISPLAY_S3
#include <display.hpp>
using namespace gfx;
#ifdef ARDUINO
#include <Wire.h>
touch_t touch(Wire);
#else
#include <driver/i2c.h>
touch_t touch(I2C_NUM_0);
#endif
#endif

#ifdef T_DISPLAY_S3
#ifdef ARDUINO
static arduino::int_button<0,10,true> button1_raw;
static arduino::int_button<14,10,true> button2_raw;
#else
static esp_idf::int_button<0,10,true> button1_raw;
static esp_idf::int_button<14,10,true> button2_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw),
    button_t(button2_raw)
};
#endif

#ifdef TTGO_T1
#ifdef ARDUINO
static arduino::int_button<0,10,true> button1_raw;
static arduino::int_button<35,10,true> button2_raw;
#else
static esp_idf::int_button<0,10,true> button1_raw;
static esp_idf::int_button<35,10,true> button2_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw),
    button_t(button2_raw)
};
#endif

#ifdef M5STACK_FIRE
#ifdef ARDUINO
static arduino::int_button<39,10,true> button1_raw;
static arduino::int_button<38,10,true> button2_raw;
static arduino::int_button<37,10,true> button3_raw;
#else
static esp_idf::int_button<39,10,true> button1_raw;
static esp_idf::int_button<38,10,true> button2_raw;
static esp_idf::int_button<37,10,true> button3_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw),
    button_t(button2_raw),
    button_t(button3_raw)
};
#endif

#ifdef M5STACK_CORE2
#include <display.hpp>
using namespace gfx;
#ifdef ARDUINO
#include <Wire.h>
touch_t touch(Wire1);
#else
#include <driver/i2c.h>
touch_t touch(I2C_NUM_1);
#endif
#endif

#ifdef S3_T_QT
#ifdef ARDUINO
static arduino::int_button<0,10,true> button1_raw;
static arduino::int_button<47,10,true> button2_raw;
#else
static esp_idf::int_button<0,10,true> button1_raw;
static esp_idf::int_button<47,10,true> button2_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw),
    button_t(button2_raw)
};
#endif

#ifdef M5STACK_S3_ATOM
#ifdef ARDUINO
static arduino::int_button<41,10,true> button1_raw;
#else
static esp_idf::int_button<41,10,true> button1_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw)
};
#endif

#ifdef ESP_DISPLAY_4INCH
#include <display.hpp>
using namespace gfx;
#ifdef ARDUINO
#include <Wire.h>
touch_t touch(Wire1);
#else
#include <driver/i2c.h>
touch_t touch(I2C_NUM_1);
#endif
#endif

#ifdef ESP_DISPLAY_4_3INCH
#include <display.hpp>
using namespace gfx;
#ifdef ARDUINO
#include <Wire.h>
touch_t touch(Wire1);
#else
#include <driver/i2c.h>
touch_t touch(I2C_NUM_1);
#endif
#endif

#ifdef HELTEC_WIFI_KIT_V2
#ifdef ARDUINO
static arduino::int_button<0,10,true> button1_raw;
#else
static esp_idf::int_button<0,10,true> button1_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw)
};
#endif

#ifdef WIO_TERMINAL
#ifdef ARDUINO
static arduino::int_button<WIO_5S_LEFT,10,true> button1_raw;
static arduino::int_button<WIO_5S_UP,10,true> button2_raw;
static arduino::int_button<WIO_5S_RIGHT,10,true> button3_raw;
static arduino::int_button<WIO_5S_DOWN,10,true> button4_raw;
static arduino::int_button<WIO_5S_PRESS,10,true> button5_raw;
button_t buttons[] = {
    button_t(button1_raw),
    button_t(button2_raw),
    button_t(button3_raw),
    button_t(button4_raw),
    button_t(button5_raw)
};
#endif
#endif

#ifdef T5_4_7
#ifdef ARDUINO
static arduino::int_button<39,10,true> button1_raw;
static arduino::int_button<34,10,true> button2_raw;
static arduino::int_button<35,10,true> button3_raw;
static arduino::int_button<0,10,true> button4_raw;
#else
static esp_idf::int_button<39,10,true> button1_raw;
static esp_idf::int_button<34,10,true> button2_raw;
static esp_idf::int_button<35,10,true> button3_raw;
static esp_idf::int_button<0,10,true> button4_raw;
#endif
button_t buttons[] = {
    button_t(button1_raw),
    button_t(button2_raw),
    button_t(button3_raw),
    button_t(button4_raw)
};
#endif

#if defined(HAS_BUTTONS) && __has_include(<button.hpp>)
bool buttons_initialize() {
    for(size_t i = 0;i<buttons_size;++i) {
        buttons[i].initialize();
    } 
    return true;
}
void buttons_update() {
    for(size_t i = 0;i<buttons_size;++i) {
        buttons[i].update();
    }
}
#endif
#if defined(HAS_TOUCH) && __has_include(<ft6236.hpp>)
bool touch_initialize() {
#if defined(ESP_DISPLAY_S3)
#ifdef ARDUINO
    Wire.begin(38,39,100*1000);
#else
    i2c_config_t i2c_conf;                                 
    i2c_conf.mode = I2C_MODE_MASTER;                       
    i2c_conf.sda_io_num = (gpio_num_t)38;     
    i2c_conf.sda_pullup_en = GPIO_PULLUP_ENABLE;           
    i2c_conf.scl_io_num = (gpio_num_t)39;     
    i2c_conf.scl_pullup_en = GPIO_PULLUP_ENABLE;           
    i2c_conf.master.clk_speed = 100*1000;                
    i2c_conf.clk_flags = 0;                                
    i2c_param_config(I2C_NUM_0, &i2c_conf);                
    i2c_driver_install(I2C_NUM_0, i2c_conf.mode, 0, 0, 0); 
#endif
#endif

    if(!touch.initialize()) {
        return false;
    }
#ifdef TOUCH_ROTATION
    touch.rotation(TOUCH_ROTATION);
#endif
    return true;
}
static void uix_touch(point16* out_locations, size_t* in_out_locations_size, void* state) {
     if (touch.update()) {                                                  
        if (touch.xy(&out_locations[0].x, &out_locations[0].y)) {          
            if (*in_out_locations_size > 1) {                              
                *in_out_locations_size = 1;                                
                if (touch.xy2(&out_locations[1].x, &out_locations[1].y)) { 
                    *in_out_locations_size = 2;                            
                }                                                          
            } else {                                                       
                *in_out_locations_size = 1;                                
            }                                                              
        } else {                                                           
            *in_out_locations_size = 0;                                    
        }                                                                  
    }
}
void touch_activate_screen() {
    if(active_screen!=nullptr) {
        active_screen->on_touch_callback(uix_touch);
    }
}
#endif
#if defined(HAS_TOUCH) && __has_include(<ft6336.hpp>)
bool touch_initialize() {
    if(!touch.initialize()) {
        return false;
    }
#ifdef TOUCH_ROTATION
    touch.rotation(TOUCH_ROTATION);
#endif
    return true;
}
static void uix_touch(point16* out_locations, size_t* in_out_locations_size, void* state) {
#ifdef ARDUINO
    delay(1);
#else
    vTaskDelay(pdMS_TO_TICKS(1));                                          
#endif
    if (touch.update()) {                                                  
        if (touch.xy(&out_locations[0].x, &out_locations[0].y)) {          
            if (*in_out_locations_size > 1) {                              
                *in_out_locations_size = 1;                                
                if (touch.xy2(&out_locations[1].x, &out_locations[1].y)) { 
                    *in_out_locations_size = 2;                            
                }                                                          
            } else {                                                       
                *in_out_locations_size = 1;                                
            }                                                              
        } else {                                                           
            *in_out_locations_size = 0;                                    
        }                                                                  
    }
}
void touch_activate_screen() {
    if(active_screen!=nullptr) {
        active_screen->on_touch_callback(uix_touch);
    }
}
#endif
#if defined(HAS_TOUCH) && __has_include(<gt911.hpp>)
#ifndef ARDUINO
#include <driver/i2c.h>
#endif
bool touch_initialize() {
#if defined(ESP_DISPLAY_4INCH) || defined(ESP_DISPLAY_4_3INCH)
#ifdef ARDUINO
    Wire1.begin(17,18);
    Wire1.setClock(400*1000);
#else
    i2c_config_t i2c_conf;                                 
    i2c_conf.mode = I2C_MODE_MASTER;                       
    i2c_conf.sda_io_num = (gpio_num_t)17;     
    i2c_conf.sda_pullup_en = GPIO_PULLUP_ENABLE;           
    i2c_conf.scl_io_num = (gpio_num_t)18;     
    i2c_conf.scl_pullup_en = GPIO_PULLUP_ENABLE;           
    i2c_conf.master.clk_speed = 400*1000;                
    i2c_conf.clk_flags = 0;                                
    i2c_param_config(I2C_NUM_1, &i2c_conf);                
    i2c_driver_install(I2C_NUM_1, i2c_conf.mode, 0, 0, 0); 
#endif
#endif
    return touch.initialize();
}
static void uix_touch(point16* out_locations, size_t* in_out_locations_size, void* state) {
    touch.update();
    size_t touches = touch.locations_size();    
    if (touches) {                              
        if (touches > *in_out_locations_size) { 
            touches = *in_out_locations_size;   
        }                                       
        decltype(touch)::point pt[5];           
        touch.locations(pt, &touches);          
        for (uint8_t i = 0; i < touches; i++) { 
            out_locations[i].x = pt[i].x;       
            out_locations[i].y = pt[i].y;       
        }                                       
    }                                           
    *in_out_locations_size = touches;
}
void touch_activate_screen() {
    if(active_screen!=nullptr) {
        active_screen->on_touch_callback(uix_touch);
    }
}
#endif