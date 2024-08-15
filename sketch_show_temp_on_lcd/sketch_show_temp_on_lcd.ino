#include <LiquidCrystal_I2C.h>

constexpr int temp_pin = A0;

LiquidCrystal_I2C lcd(0x38, 16, 2);

float readTemp(){
  int tmpADC = analogRead(temp_pin);
  float tempVolts = (tmpADC * 5.0) / 1024.0;
  float tempData = (tempVolts - 0.5) * 100;
  return tempData;
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  float temp = readTemp();
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  delay(1200);
  lcd.clear();
}
