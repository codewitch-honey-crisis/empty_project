#pragma once
#if __has_include(<Arduino.h>)
#include <Arduino.h>
#else
#include <stdint.h>
#include <stddef.h>
#endif
#ifdef ESP_DISPLAY_S3
#include <ft6236.hpp>
#define HAS_TOUCH
#define TOUCH_ROTATION 1
#ifdef ARDUINO
using touch_t = arduino::ft6236<480,320>;
#else
using touch_t = esp_idf::ft6236<480,320>;
#endif
extern touch_t touch;
extern void touch_initialize();
extern void touch_activate_screen();
#endif
#ifdef T_DISPLAY_S3
#include <button.hpp>
#define HAS_BUTTONS
#ifdef ARDUINO
using button_t = arduino::multi_button;
#else
using button_t = esp_idf::multi_button;
#endif
constexpr static const size_t buttons_size = 2;
extern button_t buttons[];
extern void buttons_initialize();
extern void buttons_update();
#endif
#ifdef TTGO_T1
#include <button.hpp>
#define HAS_BUTTONS
#ifdef ARDUINO
using button_t = arduino::multi_button;
#else
using button_t = esp_idf::multi_button;
#endif
constexpr static const size_t buttons_size = 2;
extern button_t buttons[];
extern void buttons_initialize();
extern void buttons_update();
#endif
#ifdef M5STACK_FIRE
#include <button.hpp>
#define HAS_BUTTONS
#ifdef ARDUINO
using button_t = arduino::multi_button;
#else
using button_t = esp_idf::multi_button;
#endif
constexpr static const size_t buttons_size = 3;
extern button_t buttons[];
extern void buttons_initialize();
extern void buttons_update();
#endif
#ifdef M5STACK_CORE2
#include <ft6336.hpp>
#define HAS_TOUCH
#ifdef ARDUINO
using touch_t = arduino::ft6336<280,320,39>;
#else
using touch_t = esp_idf::ft6336<280,320,39>;
#endif
extern touch_t touch;
extern void touch_initialize();
#endif
#ifdef S3_T_QT
#include <button.hpp>
#define HAS_BUTTONS
#ifdef ARDUINO
using button_t = arduino::multi_button;
#else
using button_t = esp_idf::multi_button;
#endif
constexpr static const size_t buttons_size = 2;
extern button_t buttons[];
extern void buttons_initialize();
extern void buttons_update();
#endif
#ifdef M5STACK_S3_ATOM
#include <button.hpp>
#define HAS_BUTTONS
#ifdef ARDUINO
using button_t = arduino::multi_button;
#else
using button_t = esp_idf::multi_button;
#endif
constexpr static const size_t buttons_size = 1;
extern button_t buttons[];
extern void buttons_initialize();
extern void buttons_update();
#endif
#ifdef ESP_DISPLAY_4INCH
#include <gt911.hpp>
#define HAS_TOUCH
#ifdef ARDUINO
using touch_t = arduino::gt911<38>;
#else
using touch_t = esp_idf::gt911<38>;
#endif
extern touch_t touch;
extern void touch_initialize();
#endif
#ifdef ESP_DISPLAY_4_3INCH
#include <gt911.hpp>
#define HAS_TOUCH
#ifdef ARDUINO
using touch_t = arduino::gt911<38>;
#else
using touch_t = esp_idf::gt911<38>;
#endif
extern touch_t touch;
extern void touch_initialize();
#endif
#ifdef WIO_TERMINAL
// TODO: Implement 5-way switch
#endif
#ifdef T5_4_7
#include <button.hpp>
#define HAS_BUTTONS
#ifdef ARDUINO
using button_t = arduino::multi_button;
#else
using button_t = esp_idf::multi_button;
#endif
constexpr static const size_t buttons_size = 4;
extern button_t buttons[];
extern void buttons_initialize();
extern void buttons_update();
#endif