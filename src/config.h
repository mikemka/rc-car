#pragma once

// ==== PINS ====
#define SDA_PIN 6
#define SCL_PIN 7
#define SERVO_PIN 3
#define ESC_PIN   4
#define VBAT_PIN  0
#define ELRS_RX   20
#define ELRS_TX   21

// ==== I2C ====
#define OLED_ADDR 0x3C
#define MPU_ADDR  0x68
#define MPU_PWR_MGMT_1  0x6B
#define MPU_GYRO_ZOUT_H 0x47

// ==== ELRS ====
#define ELRS_BAUD 420000

// ==== CONTROL ====
#define YAW_RC_KP     0.5f
#define YAW_GYRO_KP   1.0f
#define TROTTLE_KP    1.0f
#define GYRO_ALPHA    0.1f

// ==== VBAT ====
#define R1 8900.0f
#define R2 1000.0f
