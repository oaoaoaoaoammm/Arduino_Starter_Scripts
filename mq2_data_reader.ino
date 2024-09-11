#include <MQ2.h> // библиотека для датчика

  

MQ2 mq2(A1); // создаём объект для работы с датчиком

  

int lpg, co, smoke;

  

void setup() {

Serial.begin(9600);

mq2.begin();

}

  

void loop() {

float* values = mq2.read(true);

  

// получаем информацию с датчика

// выводим данные на монитор порта

lpg = mq2.readLPG();

co = mq2.readCO();

smoke = mq2.readSmoke();

  

delay(1000);

}
