// Даём понятное имя пину с датчиком температуры TMP36
constexpr int TMP36_PIN = A0;
 
void setup() {
  // Открываем соединения с последовательным портом
  Serial.begin(9600);
}
 
void loop() {
  // Считываем аналоговый сигнал с TMP36
  int tmp36ADC = analogRead(TMP36_PIN);
  // Преобразуем отсчёты АЦП в напряжение
  float tmp36Voltage = (tmp36ADC * 5.0) / 1024.0;
  // Преобразуем напряжение с датчика в значение температуры
  float tmp36Temperature = (tmp36Voltage - 0.5) * 100;
  // Выводим результаты измерений в терминал
  Serial.print(tmp36ADC);
  Serial.print(" ADC");
  Serial.print("\t\t");
  Serial.print(tmp36Voltage);
  Serial.print(" Volts");
  Serial.print("\t");
  Serial.print(tmp36Temperature);
  Serial.println(" Degrees C");
  delay(1000);
}