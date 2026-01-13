#include <Arduino.h>
#include "config.h"
#include "vbat.h"

float readVbat() {
    int raw = analogRead(VBAT_PIN);
    float vadc = raw * 3.3f / 4095.0f;
    return vadc * (R1 + R2) / R2;
}
