# empty project

This is a starter project including display, input and power management supporting several devices. Both Arduino and the ESP-IDF are supported.

the display code features htcw_gfx and htcw_uix for drawing graphics and using user interface controls

the input code depends on the device and includes my htcw_button library and various touch libraries I've provided

It's relatively easy to add support for more devices and platforms.

Device support:

- Lilygo T-Display S3
- Lilygo TTGO T-Display T1
- M5 Stack Fire
- M5 Stack Core2
- M5 Stack S3 Atom
- Makerfabs ESP Display S3 Parallel w/ Touch
- Makerfabs ESP Display S3 4 inch w/ Touch
- Makerfabs ESP Display S3 4.3 inch w/ Touch
- Espressif ESP_WROVER_KIT 4.1
- Lilygo T-QT (and Pro)
- HelTec WiFi Kit V2
- Wio Terminal
- Lilygo T5 4.7" E-Paper

main.cpp contains the main application starting point and loop (both Arduino and ESP-IDF)

ui.hpp and ui.cpp include the user interface code.

The rest is more or less hands off unless you're adding devices, in which case you may need to modify display.hpp/cpp, and possibly lcd_config.h for screens, input.hpp/cpp for buttons or touch maybe power.hpp/cpp for power management. You'll of course need to edit the platformio.ini as well.