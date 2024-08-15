constexpr int temp = A0;

float readTemp(){
  int tmpADC = analogRead(temp);
  float tempVolts = (tmpADC * 5.0) / 1024.0;
  float tempData = (tempVolts - 0.5) * 100;
  return tempData;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = readTemp();
  Serial.print("Temperature C: ");
  Serial.println(temp);
  delay(100);
}
