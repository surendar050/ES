#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  client.setServer(mqtt_server, 1883);
}

void loop()
{
  if (!client.connected())
  {
    client.connect("ESP32_Client");
  }

  int sensor = analogRead(34);

  char data[10];
  sprintf(data, "%d", sensor);

  client.publish("sensor/light", data);

  Serial.println(data);

  client.loop();

  delay(2000);
}