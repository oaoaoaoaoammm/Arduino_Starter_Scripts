constexpr int leds [] = {2,3,4,5};
constexpr int count_leds = 4;


void setup() {
  for(int i = 0; i < count_leds; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < count_leds; i++){
    delay(1000);
    digitalWrite(leds[i], true);
  }

  for(int i = 0; i < count_leds; i++){
    delay(1000);
    digitalWrite(leds[i], false);
  }
}
