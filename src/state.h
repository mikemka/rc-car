#pragma once
#include <stdint.h>

extern bool armed;

extern float gyroZ_raw;
extern float gyroZ_filt;

extern uint16_t servoOut;
extern uint16_t escOut;

extern float vbat;
