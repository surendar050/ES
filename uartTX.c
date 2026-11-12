#include <SoftwareSerial.h>

SoftwareSerial uart(10, 11);

void setup()
{
  uart.begin(9600);
}

void loop()
{
  uart.println("Hello Arduino 2");
  delay(1000);
}