#include <SPI.h>

constexpr int latch_pin = 10;

byte leds = 0b000000;


void setup() {
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  pinMode(latch_pin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 8; i++){
    bitWrite(leds, i,true);
    sendData();
    delay(100);
  }
  for(int i = 0; i<8;i++){
    bitWrite(leds, i,false);
    sendData();
    delay(100);
  }
}

void sendData(){
  digitalWrite(latch_pin, false);
  SPI.transfer(leds);
  digitalWrite(latch_pin, true);
}
