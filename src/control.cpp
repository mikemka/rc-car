#include <Arduino.h>
#include <ESP32Servo.h>

#include "config.h"
#include "state.h"
#include "elrs.h"
#include "mpu.h"

Servo steering;
Servo esc;

bool armed = false;
uint16_t servoOut = 1500;
uint16_t escOut   = 1000;

void controlInit() {
    steering.setPeriodHertz(50);
    esc.setPeriodHertz(50);

    steering.attach(SERVO_PIN, 1000, 2000);
    esc.attach(ESC_PIN, 1000, 2000);

    steering.writeMicroseconds(1500);
    esc.writeMicroseconds(1000);
}

void controlUpdate() {
    uint16_t thr = elrsGet(3);
    uint16_t yaw = elrsGet(4);
    armed = elrsGet(5) > 1500 && elrsLink();
    uint8_t gyroMix = map(constrain(elrsGet(10),1000,2000),1000,2000,0,100);

    if (!armed) {
        escOut = 1000;
        servoOut = 1500;
    } else {
        escOut = (thr - 1000) * TROTTLE_KP + 1000;

        int yawRc = (yaw - 1500) * 2 * YAW_RC_KP;
        int yawGyro = gyroZ_filt * YAW_GYRO_KP * gyroMix / 50;

        servoOut = constrain(1500 + yawRc - yawGyro, 1000, 2000);
    }

    steering.writeMicroseconds(servoOut);
    esc.writeMicroseconds(escOut);
}
