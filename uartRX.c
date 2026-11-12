#include <SoftwareSerial.h>

SoftwareSerial uart(10, 11);

void setup()
{
  Serial.begin(9600);
  uart.begin(9600);
}

void loop()
{
  if (uart.available())
  {
    char data = uart.read();
    Serial.print(data);
  }
}