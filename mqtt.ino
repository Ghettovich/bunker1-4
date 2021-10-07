// Update these with values suitable for your network.
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 178, 22);
IPAddress server(192, 168, 178, 251);

const char pulseCountTopic[] = "auger/pulsecount";

EthernetClient ethClient;
PubSubClient client(ethClient);


void setupMqttClient() {
  // TODO set proper buffer size
  //client.setBufferSize(256);
  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
}

void mqttLoop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();
}

void callback(char* topic, byte* payload, unsigned int len) {
  if (strcmp(pulseCountTopic, topic) == 0) {
    Serial.println("reset pulse count");
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient2")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      

      // ... and resubscribe
      client.subscribe(pulseCountTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void publishPulseCount() {
  Serial.println("publish pulse count");
}

void publishDistance() {
  
}
