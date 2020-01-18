#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

#define LIGHT_SENSOR_PIN 54

LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;

void setup() {
    pinMode(LIGHT_SENSOR_PIN, INPUT);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Counter value: ");
    lcd.setCursor(0, 1);
}

void loop() {

    int lightRaw = analogRead(LIGHT_SENSOR_PIN);
    Serial.begin(9600);
    Serial.println(lightRaw);
    if (lightRaw < 500) {
        counter++;
        lcd.setCursor(0, 1);
        lcd.print(counter);
        delay(400);
    }
}