#include <LiquidCrystal_I2C.h>
#include <TroykaButton.h>

constexpr int temp_pin = A0;
constexpr int green_led = 6;
constexpr int red_led = 9;

LiquidCrystal_I2C lcd(0x38, 16, 2);
 
TroykaButton button_h(2);
TroykaButton button_m(3);
TroykaButton button_s(4);

int hours, minutes, seconds;

long millisLastTime = 0;
long millisLastTemp = 0;
float temp = 0;

float readTemp(){
  int tmpADC = analogRead(temp_pin);
  float tempVolts = (tmpADC * 5.0) / 1024.0;
  float tempData = (tempVolts - 0.5) * 100;
  return tempData;
}


void setup() {
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  lcd.init();
  button_h.begin();
  button_m.begin();
  button_s.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  updateTime();
  updateTimeButtons();
  wrapTime();
  updateTemp();
  printDataLCD();
  ledStatus();
}


void setTime(int h, int m, int s){
  hours = h;
  minutes = m;
  seconds = s;
}

void updateTime(){
  long millisNowTime = millis();
  if (millisNowTime - millisLastTime > 1000){
    millisLastTime = millisNowTime;
    seconds++;
  }
}

void updateTimeButtons(){
  button_h.read();
  button_m.read();
  button_s.read();

  if(button_h.isClick()){
    hours++;
  }
  if(button_m.isClick()){
    minutes++;
  }
  if(button_s.isClick()){
    seconds++;
  }
}

void wrapTime(){
  if(seconds >= 60){
    minutes++;
    seconds = 0;
  }
  if(minutes >= 60){
    hours++;
    minutes = 0;
  }
  if(hours >= 12){
    hours = 0;
  }
}

void updateTemp(){
  long millisNowTemp = millis();
  if (millisNowTemp - millisLastTemp > 1000){
    millisLastTemp = millisNowTemp;
    temp = readTemp();
  }
}

void printDataLCD(){
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printTwoDigits(hours);
  lcd.print(":");
  printTwoDigits(minutes);
  lcd.print(":");
  printTwoDigits(seconds);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
}

void printTwoDigits(int digit){
  if (digit < 10){
    lcd.print("0");
  }
  lcd.print(digit);
}

void ledStatus(){
  if(temp >= 33.0){
     analogWrite(green_led, 0);
     analogWrite(red_led, 20);
  }
  if(temp <= -10.0){
     analogWrite(green_led, 0);
     analogWrite(red_led, 20);
  }
  if(temp < 33.0 && temp > -10.0){
     analogWrite(green_led, 20);
     analogWrite(red_led, 0);
  }
}
