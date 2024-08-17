#define first_seg_pin 2
#define seg_count 7

byte numSeg[10] = {0b00111111, 0b00001010, 0b01011101, 0b01011110, 0b01101010, 0b01110110, 0b01110111, 0b00011010, 0b01111111, 0b01111110};



void setup() {
  for(int i =0; i<seg_count;i++){
    pinMode(first_seg_pin + i, OUTPUT);
  }

}

void loop() {
  int num = (millis() / 1000) % 10;
  int mask = numSeg[num];
  for(int i =0; i<seg_count;i++){
    boolean enSeg = bitRead(mask, i);
    digitalWrite(first_seg_pin + i, enSeg);
  }
}
