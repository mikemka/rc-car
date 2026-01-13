#include <Wire.h>
#include "config.h"
#include "state.h"

float gyroZ_raw = 0;
float gyroZ_filt = 0;

void mpuInit() {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(MPU_PWR_MGMT_1);
    Wire.write(0);
    Wire.endTransmission();
}

void mpuUpdate() {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(MPU_GYRO_ZOUT_H);
    if (Wire.endTransmission(false) != 0) return;
    if (Wire.requestFrom(MPU_ADDR, (uint8_t)2) != 2) return;

    int16_t gz = (Wire.read() << 8) | Wire.read();
    gyroZ_raw = gz / 131.0f;
    gyroZ_filt += (gyroZ_raw - gyroZ_filt) * GYRO_ALPHA;
}
