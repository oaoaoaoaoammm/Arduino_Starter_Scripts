#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38, 16,2);

constexpr int volt_pin = A0;
constexpr float R1 = 10000;
constexpr float R2 = 1000;
constexpr float k = R2/(R2+R1);

constexpr int lcd_icon_but_1 = 0x9B;
constexpr int lcd_icon_but_2 = 0x9C;
constexpr int lcd_icon_but_3 = 0x9D;
constexpr int lcd_icon_but_4 = 0x9E;
constexpr int lcd_icon_but_5 = 0x9F;



void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Charge indicator");
}

void loop() {
  float batVol = readVol();
  lcd.setCursor(0, 1);
  lcd.print(batVol);
  lcd.print(" V / ");

  if(batVol >= 9){
    lcd.write(lcd_icon_but_1);
  }
  else if (batVol >= 8){
    lcd.write(lcd_icon_but_2);
  }
  else if (batVol >= 7){
    lcd.write(lcd_icon_but_3);
  }
  else if (batVol >= 6){
    lcd.write(lcd_icon_but_4);
  }
  else{
    lcd.write(lcd_icon_but_5);
  }
  delay(1000);
}

float readVol(){
  int batADC = analogRead(volt_pin);
  float batVolt = ((batADC * 5.0) / 1024.0) / k;
  return batVolt;
}
