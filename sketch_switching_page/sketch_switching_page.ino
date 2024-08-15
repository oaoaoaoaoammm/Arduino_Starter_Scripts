#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38, 16,2);

constexpr int page_0 = 0b101000;
constexpr int page_1 = 0b101010;


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Gay");
  lcd.setCursor(5,1);
  lcd.print("\x9f\x9e\x9d\x9c\x9b");
}

void loop() {
  lcd.command(page_0);
  delay(2000);
  lcd.command(page_1);
  delay(2000);
}
