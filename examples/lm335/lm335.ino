/* lm335 библиотека для работы
 с аналоговым датчиком температуры lm335 
 подходит и для других датчиков, например lm235.
 Автор - Захаров Леонид.
 Авторский видеоканал: https://www.youtube.com/channel/UCj9y09JX-zu_y3uCremKK4w
 Создана по материалам сайтов 
 http://arduino.ru/Hacking/LibraryTutorial
 http://mypractic.ru/urok-9-sozdanie-biblioteki-dlya-arduino.html */


#include <Lm335.h> // Подключаем библиотеку

const int datchik_1 = 0; // Определяем аналоговые пины для поключения датчиков в зависимости от их количества
const int datchik_2 = 1;

/* Переменные, для которых мы будем получать дванные с датчиков:*/
double volt;      // Напряжение на датчике - для его настройки, В
double temper;    // Температура, градусов по Цельсию
int temper_out;   // Температура, округленная до целых значений, градусов по Цельсию

double U_vcc = 4.95;     // Здесь указываем точное напряжение питания датчика

// Создаем объекты для датчиков в соответствии с их количеством
Lm335 lm3351(datchik_1,U_vcc);   // Создаем объект для датчика 1
Lm335 lm3352(datchik_2,U_vcc);   // Создаем объект для датчика 2

void setup() {
Serial.begin(9600);
}

void loop() {
  // Для датчика 1:
lm3351.datchikVozdAnalog();         // Вызов метода определения параметров для датчика 1
Serial.print("1.U=");
volt = lm3351.volt335;              // Можно получить напряжение на датчике 1 (для настройки)
Serial.println(volt);     
Serial.print("1.Temper_1=");
temper = lm3351.temp335;            // Получаем температуру с датчика 1
Serial.println(temper);
Serial.print("1.Temper_2=");
temper_out = lm3351.temp335_out;    // Получаем температуру, округленную до целых значений
Serial.println(temper_out);
delay(1000);

  // Для датчика 2:
lm3352.datchikVozdAnalog();         // Вызов метода определения параметров для датчика 2
Serial.print("2.U=");
volt = lm3352.volt335;              // Можно получить напряжение на датчике 2 (для настройки)
Serial.println(volt);     
Serial.print("2.Temper_1=");
temper = lm3352.temp335;            // Получаем температуру с датчика 2
Serial.println(temper);
Serial.print("2.Temper_2=");
temper_out = lm3352.temp335_out;    // Получаем температуру, округленную до целых значений
Serial.println(temper_out);
delay(2000); 

}
