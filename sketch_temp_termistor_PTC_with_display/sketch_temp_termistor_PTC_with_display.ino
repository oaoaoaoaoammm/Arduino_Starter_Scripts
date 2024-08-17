#include <math.h>

#define term_pin A0
#define first_led 2
#define led_counts 10

float voltage = 0.0;
float temp = 0.0;

void setup() {
  for(int i = 0; i < led_counts; i++){
    pinMode(first_led + i, OUTPUT);  
  }
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(term_pin) * 5.0 / 1023.0;
  temp = 1.0 / (log(voltage / 2.5) / 4300.0 + 1.0 / 298.0) - 273.0;

  for(int i = 0; i < led_counts; i++){
    bool en_seg = (temp >= 21+i);
    digitalWrite(first_led + i, en_seg);  
  }

  Serial.println(temp);
  delay(100);
}