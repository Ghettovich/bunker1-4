#include <SPI.h>
#include <EthernetENC.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("[Bunker1-4]");

  setupMqttClient();
  Serial.println("Ethernet Ready.");

  setupProximity();
  Serial.println("Proxmity Ready");

  setupSonar();
  Serial.println("Sonar Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  usLoop();
  proximityLoop();
  mqttLoop();
}
