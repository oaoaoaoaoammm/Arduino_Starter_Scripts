constexpr int pin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  int sensorADC = analogRead(pin);
  float sensorData = (sensorADC * 5.0) / 1024.0;
  Serial.println(sensorADC);
  Serial.println("");
  Serial.print("Volts: ");
  Serial.println(sensorData);
  delay(100);
}
