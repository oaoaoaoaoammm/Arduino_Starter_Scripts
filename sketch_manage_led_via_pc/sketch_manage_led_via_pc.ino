#define led_pin 9
String message;

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()){
    char income = Serial.read();
    Serial.println(income);
    if(income >= '0' && income <= '9'){
      message += income;
    }
    else if(income == '\n'){
      analogWrite(led_pin, message.toInt()*10);
      message = "";
    }
  }
}
