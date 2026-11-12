int ENA = 9;
int IN1 = 7;
int IN2 = 8;

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop()
{
  // Forward direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA, 150);  // Speed control
  delay(3000);

  // Reverse direction
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENA, 200);
  delay(3000);

  // Stop motor
  analogWrite(ENA, 0);
  delay(2000);
}