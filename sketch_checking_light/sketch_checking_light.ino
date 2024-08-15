#include <LiquidCrystal_I2C.h>

constexpr int ldr_pin = A3;

LiquidCrystal_I2C lcd(0x38, 16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Luxe");
  pinMode(ldr_pin, INPUT);
}

void loop() {
  long ldrData = analogRead(ldr_pin);
  String ldrLS = longToStr(ldrData, 6);
  lcd.setCursor(0, 1);
  lcd.print(ldrLS);
  lcd.print(" LX");
  delay(1000);
}

String longToStr(long value, int countDigits){
  String valueS;
  value = value*10;
  int lenV = String(value).length();
  for(int i = countDigits; i > lenV; i --){
    valueS+= "0";
  }
  valueS += String(value);
  return valueS;
}
