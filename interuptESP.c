#define BUTTON 18
#define LED 2

volatile bool flag = false;

void IRAM_ATTR interruptFunction()
{
  flag = true;
}

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  attachInterrupt(
    digitalPinToInterrupt(BUTTON),
    interruptFunction,
    FALLING
  );
}

void loop()
{
  if (flag)
  {
    digitalWrite(LED, !digitalRead(LED));
    flag = false;
  }
}