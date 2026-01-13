#include <Arduino.h>
#include <AlfredoCRSF.h>
#include <HardwareSerial.h>

#include "config.h"
#include "elrs.h"

static HardwareSerial crsfSerial(1);
static AlfredoCRSF crsf;

void elrsInit() {
    crsfSerial.begin(ELRS_BAUD, SERIAL_8N1, ELRS_RX, ELRS_TX);
    crsf.begin(crsfSerial);
}

void elrsUpdate() {
    crsf.update();
}

bool elrsLink() {
    return crsf.isLinkUp();
}

int elrsGet(uint8_t ch) {
    return crsf.getChannel(ch);
}

void elrsSendBattery(float vbat) {
    crsf_sensor_battery_t batt = {0};

    uint16_t voltage16 = vbat * 10.0f;
    uint8_t *raw = (uint8_t *)&batt;

    raw[0] = voltage16 >> 8;
    raw[1] = voltage16 & 0xFF;

    crsf.queuePacket(
        CRSF_SYNC_BYTE,
        CRSF_FRAMETYPE_BATTERY_SENSOR,
        &batt,
        sizeof(batt)
    );
}
