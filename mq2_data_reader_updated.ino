#include <MQUnifiedsensor.h>

// Настройки датчика
#define Board "Arduino UNO"
#define Pin A1  // Аналоговый вход
#define Voltage_Resolution 5
#define ADC_Bit_Resolution 10
#define RatioMQ2CleanAir 9.83  // Отношение RS / R0 в чистом воздухе для MQ-2

// Инициализация датчика MQ-2
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, "MQ-2");

void setup() {
  Serial.begin(9600); // Инициализация серийного порта

  // Установка модели для расчета концентрации PPM и значений коэффициентов
  MQ2.setRegressionMethod(1); // PPM = a * ratio^b
  
  // Настройка коэффициентов для каждого газа
  MQ2.setA(574.25); MQ2.setB(-2.222); // LPG
  MQ2.setA(36974); MQ2.setB(-3.109); // CO
  MQ2.setA(987.99); MQ2.setB(-2.162); // H2
  MQ2.setA(658.71); MQ2.setB(-2.168); // Propane
  MQ2.setA(3616.1); MQ2.setB(-2.675); // Alcohol
  MQ2.setA(3616.1); MQ2.setB(-2.675); // Butane (можно заменить коэффициенты на точные для Butane)

  // Инициализация и калибровка датчика
  MQ2.init();
  
  Serial.print("Calibrating, please wait.");
  float calcR0 = 0;
  for(int i = 1; i <= 10; i++) {
    MQ2.update();
    calcR0 += MQ2.calibrate(RatioMQ2CleanAir);
    Serial.print(".");
  }
  MQ2.setR0(calcR0 / 10);
  Serial.println(" done!");

  // Проверка значений R0
  if(isinf(calcR0)) {
    Serial.println("Warning: Connection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
    while(1);
  }
  if(calcR0 == 0) {
    Serial.println("Warning: Connection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
    while(1);
  }
}

void loop() {
  MQ2.update(); // Обновляем данные с датчика

  // Расчет концентраций газов
  MQ2.setA(574.25); MQ2.setB(-2.222); // LPG
  float lpg_concentration = MQ2.readSensor();
  Serial.print("LPG: ");
  Serial.print(lpg_concentration);
  Serial.println(" ppm");

  MQ2.setA(36974); MQ2.setB(-3.109); // CO
  float co_concentration = MQ2.readSensor();
  Serial.print("CO: ");
  Serial.print(co_concentration);
  Serial.println(" ppm");

  MQ2.setA(987.99); MQ2.setB(-2.162); // H2
  float h2_concentration = MQ2.readSensor();
  Serial.print("H2: ");
  Serial.print(h2_concentration);
  Serial.println(" ppm");

  MQ2.setA(658.71); MQ2.setB(-2.168); // Propane
  float propane_concentration = MQ2.readSensor();
  Serial.print("Propane: ");
  Serial.print(propane_concentration);
  Serial.println(" ppm");

  MQ2.setA(3616.1); MQ2.setB(-2.675); // Alcohol
  float alcohol_concentration = MQ2.readSensor();
  Serial.print("Alcohol: ");
  Serial.print(alcohol_concentration);
  Serial.println(" ppm");

  delay(1000); // Задержка между измерениями
}
