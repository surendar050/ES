void Task1(void *parameter)
{
  while (1)
  {
    Serial.println("High Priority Task");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void Task2(void *parameter)
{
  while (1)
  {
    Serial.println("Low Priority Task");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(115200);

  xTaskCreate(Task1, "Task1", 2048, NULL, 2, NULL);

  xTaskCreate(Task2, "Task2", 2048, NULL, 1, NULL);
}

void loop()
{
}