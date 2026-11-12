void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(500);       // LED ON for 500 ms

  digitalWrite(13, LOW);
  delay(500);       // LED OFF for 500 ms
}