#include <GyverOLED.h>
#include "state.h"

static GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

void oledInit() {
    oled.init();
    oled.clear();
}

void oledUpdate() {
    oled.invertDisplay(armed);

    oled.setScale(2);
    oled.setCursor(0, 1);
    oled.print(vbat, 2);
    oled.print("v");

    oled.setScale(1);
    oled.setCursor(0, 3);
    oled.print("Gz:");
    oled.print(gyroZ_filt);

    oled.setCursor(0, 5);
    oled.print("S:");
    oled.print(servoOut);
    oled.print(" E:");
    oled.print(escOut);
}
