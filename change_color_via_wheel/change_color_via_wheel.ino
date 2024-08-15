constexpr int blue_led = 9;
constexpr int green_led = 11;
constexpr int red_led = 10;
constexpr int button = A0;

int red, green, blue;


void setup() {
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
 int rot = analogRead(button);
  if (rot<=170){
    red = 255;
    green = map(rot, 0, 170, 0, 255);
    blue = 0;
  }
  else if(rot <= 340){
    red = map(rot, 170, 340, 255, 0);
    green = 255;
    blue = 0;
  }
  else if(rot <= 512){
    red = 0;
    green = 255;
    blue = map(rot, 340, 512, 0, 255);
  }
  else if(rot <= 682){
    red = 0;
    green = map(rot, 512, 682, 255, 0);
    blue = 255;
  }
  else if(rot <= 852){
    red = map(rot, 682, 852, 0, 255);
    green = 0;
    blue = 255;
  }
  else{
    red = 255;
    green = 0;
    blue = map(rot, 852, 1023, 255, 0);
  }

  analogWrite(red_led, red);
  analogWrite(green_led, green);
  analogWrite(blue_led, blue);
  
}
