#include <Arduino.h>
#include <Wire.h>

#include "config.h"
#include "state.h"

#include "elrs.h"
#include "mpu.h"
#include "oled.h"
#include "vbat.h"
#include "control.h"
#include "telemetry.h"

uint32_t dbgTimer = 0;
uint32_t telemTimer = 0;
float vbat = 0;

void setup() {
    Serial.begin(115200);

    analogReadResolution(12);
    analogSetAttenuation(ADC_11db);

    Wire.begin(SDA_PIN, SCL_PIN);

    elrsInit();
    mpuInit();
    oledInit();
    controlInit();

    Serial.println("SYSTEM READY");
}

void loop() {
    elrsUpdate();
    mpuUpdate();
    controlUpdate();

    if (millis() - telemTimer > 500) {
        telemTimer = millis();
        vbat = readVbat();
        sendBatteryVoltage(vbat);
    }

    if (millis() - dbgTimer > 300) {
        dbgTimer = millis();
        oledUpdate();
    }
}
