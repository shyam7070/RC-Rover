
#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

typedef struct struct_message {
  char command[32];
} struct_message;

struct_message incomingMessage;

void onDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&incomingMessage, incomingData, sizeof(incomingMessage));
  Serial.print("Received: ");
  Serial.println(incomingMessage.command);

  if (strcmp(incomingMessage.command, "FORWARD") == 0) {
    leftMotor.write(180);
    rightMotor.write(0);
  } else if (strcmp(incomingMessage.command, "BACKWARD") == 0) {
    leftMotor.write(0);
    rightMotor.write(180);
  } else if (strcmp(incomingMessage.command, "LEFT") == 0) {
    leftMotor.write(0);
    rightMotor.write(0);
  } else if (strcmp(incomingMessage.command, "RIGHT") == 0) {
    leftMotor.write(180);
    rightMotor.write(180);
  } else if (strcmp(incomingMessage.command, "STOP") == 0) {
    leftMotor.write(90);
    rightMotor.write(90);
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  leftMotor.attach(5);  // D1
  rightMotor.attach(4); // D2

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(onDataRecv);
}

void loop() {
  // Nothing needed here, waiting for data
}
