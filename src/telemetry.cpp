#include "telemetry.h"
#include "elrs.h"

void sendBatteryVoltage(float vbat) {
    elrsSendBattery(vbat);
}
