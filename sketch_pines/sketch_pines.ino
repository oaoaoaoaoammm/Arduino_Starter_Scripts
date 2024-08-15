#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38, 16,2);

byte pines[8]={
  0b00000,
  0b00100,
  0b01010,
  0b01010,
  0b01010,
  0b10001,
  0b01110,
  0b00000
};


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0x00, pines);
  lcd.setCursor(0,0);
  lcd.write(0x00);
}

void loop() {
  // put your main code here, to run repeatedly:

}
