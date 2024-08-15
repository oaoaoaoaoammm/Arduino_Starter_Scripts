#include <LiquidCrystal.h>

constexpr int cont_2 = 2;
constexpr int cont_3 = 3;
constexpr int cont_4 = 4;
constexpr int cont_5 = 5;
constexpr int cont_6 = 6;
constexpr int cont_7 = 7;

String text_to_display = "Dorogo Dao oaoaoaooaoaoa";

LiquidCrystal lcd(cont_2, cont_3, cont_4, cont_5, cont_6, cont_7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(text_to_display);
}

void loop() {
  for(int i = 0; i < text_to_display.length()/4; i++){
    lcd.scrollDisplayLeft();
    delay(700);
  }
}
