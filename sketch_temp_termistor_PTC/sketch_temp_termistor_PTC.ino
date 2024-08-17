#include <math.h>
#define term_pin A0

float voltage = 0.0;
float temp = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(term_pin) * 5.0 / 1023.0; 
  temp = 1.0 / (log(voltage/2.5) / 4300.0 + 1.0 / 298.0) - 273.0;

  Serial.println(temp);
  delay(100);
}
