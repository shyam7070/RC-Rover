
#include <ESP8266WiFi.h>
#include <espnow.h>

uint8_t broadcastAddress[] = {0x24, 0x0A, 0xC4, 0x5B, 0x6D, 0x28};  // Receiver MAC Address

typedef struct struct_message {
  char command[32];
} struct_message;

struct_message outgoingMessage;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toCharArray(outgoingMessage.command, 32);
    esp_now_send(broadcastAddress, (uint8_t *)&outgoingMessage, sizeof(outgoingMessage));
    Serial.println("Command Sent: " + command);
  }
}
