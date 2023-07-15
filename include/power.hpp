#pragma once

#ifdef T_DISPLAY_S3
#define HAS_POWER
extern void power_initialize();
#endif

#ifdef M5STACK_CORE2
#define HAS_POWER
#include <m5core2_power.hpp>
using power_t = m5core2_power;
extern power_t power;
extern bool power_initialize();
#endif

#ifdef S3_T_QT
#define HAS_POWER
extern bool power_initialize();
#endif
