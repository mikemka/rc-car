#pragma once
#include <stdint.h>

void elrsInit();
void elrsUpdate();

bool elrsLink();
int  elrsGet(uint8_t ch);

// telemetry
void elrsSendBattery(float vbat);
