#include <Stepper.h>

const int steps = 2048;

Stepper motor(steps, 8, 10, 9, 11);

void setup()
{
  motor.setSpeed(10);
}

void loop()
{
  // Forward rotation
  motor.step(steps);
  delay(1000);

  // Reverse rotation
  motor.step(-steps);
  delay(1000);
}