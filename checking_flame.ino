int flameAnalogPin = A1; // Подключаем AO (аналоговый выход) к пину A0

int flameAnalogValue = 0; // Переменная для хранения аналогового значения

  

void setup() {

Serial.begin(9600); // Запускаем сериальный монитор

}

  

void loop() {

flameAnalogValue = analogRead(flameAnalogPin); // Читаем значение с аналогового выхода

  

Serial.print("Интенсивность пламени: ");

Serial.println(flameAnalogValue); // Выводим значение интенсивности пламени

  

delay(1000); // Задержка в 1 секунду

}
