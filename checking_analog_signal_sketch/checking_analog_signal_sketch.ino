constexpr int green_led = 3;

void setup() {
  pinMode(green_led, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int wire = analogRead(A0);
  int brightness = wire/4;
  analogWrite(green_led, brightness);
}

