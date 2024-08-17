#include <Servo.h>

#define max_angle 270.0

Servo myServ;

void setup() {
  pinMode(A0, INPUT);
  myServ.attach(9);
}

void loop() {
  int val = analogRead(A0);
  int angle = int(val / 1024.0 * max_angle);
  angle = constrain(angle, 0, 180);
  myServ.write(angle);
}
