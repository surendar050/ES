int LDR = A0;
int LED = 13;
int value;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop()
{
  value = analogRead(LDR);

  if (value < 500)
  {
    digitalWrite(LED, HIGH);
    delay(5000);     // Lamp ON for 5 seconds
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  delay(1000);
}