#define motor_pin 9
#define first_but 5
#define but_count 3

#define speed_step (255 / (but_count - 1))



int brightness = 0;

void setup() {
  pinMode(motor_pin, OUTPUT);

  for( int i = 0; i < but_count; i++){
    pinMode(first_but + i, INPUT_PULLUP);
  }
}

void loop() {
   for( int i = 0; i < but_count; i++){
    if(digitalRead(first_but + i))
      continue;

    int speed = i * speed_step;
    analogWrite(motor_pin, speed);
  }
}
