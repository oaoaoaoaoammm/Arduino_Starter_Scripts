constexpr int yellow_led = 2;
constexpr int green_led = 3;
constexpr int red_led = 4;
constexpr int button_8 = 8;

constexpr int pause = 60;

bool state = false;
bool buttonState = false;
bool last_buttonState = false;
int light_percent = 0;

void setup() {
  // pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  // pinMode(red_led, OUTPUT);

  pinMode(button_8, INPUT_PULLUP);
  // analogWrite(yellow_led, 255); яркость
  // digitalWrite(red_led, OUTPUT); просто вывод/ввод
}

void loop() {
  buttonState = !digitalRead(button_8);
  if (buttonState && !last_buttonState){
    if(buttonState){
      if(light_percent >= 255){
        light_percent = 0;
      }
      else{
        last_buttonState=!last_buttonState;
        light_percent += 10;
        analogWrite(green_led, light_percent); 
      }
    }
  }
  last_buttonState=buttonState;
}
