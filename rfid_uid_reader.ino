#include <SPI.h>

#include <MFRC522.h>

  

#define RST_PIN 9 // Пин rfid модуля RST

#define SS_PIN 10 // Пин rfid модуля SS

  

MFRC522 mfrc522(SS_PIN, RST_PIN); // Создаём объект MFRC522

  

void setup()

{

Serial.begin(9600); // Инициализация последовательного порта

SPI.begin(); // Инициализация SPI

mfrc522.PCD_Init(); // Инициализация считывателя RC522

}

  

void loop()

{

if (!mfrc522.PICC_IsNewCardPresent()) // Ожидание прикладывания RFID-метки

{

return; // Выход, если не приложена новая карта

}

if (!mfrc522.PICC_ReadCardSerial()) // Считываем данные

{

return; // Выход, если невозможно считать серийный номер

}

Serial.print("Cart UID: "); // Отправка данных в мониторинг порта

for (byte i = 0; i < mfrc522.uid.size; i++)

{

Serial.print(mfrc522.uid.uidByte[i], HEX);

}

delay(500); // Пауза

Serial.println(); // Новая строка

}
