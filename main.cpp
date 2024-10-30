#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino.h>
#include <ArduinoJson.h>

// WiFi credentials
const char* ssid     = "Loading...";
const char* password = "Finexes0621";
const char* serverUrl = "https://rckh.xyz/API_assignment/results.txt";

// Define GPIO pins for RGB LED
const int redPin = D1;
const int greenPin = D2;
const int bluePin = D3;

void setup() {
  Serial.begin(9600);
  Serial.println("");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi Connected");

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    HTTPClient http;
    client.setInsecure();
    http.begin(client, serverUrl);
    int httpCode = http.GET();
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println("Received payload: " + payload);

      StaticJsonDocument<256> doc;
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        const char* status = doc["Node1"]["LED1"]["status"];
        
        Serial.print("Status: ");
        Serial.println(status);
        
        int red = doc["Node1"]["LED1"]["red"];
        int green = doc["Node1"]["LED1"]["green"];
        int blue = doc["Node1"]["LED1"]["blue"];

        if (strcmp(status, "on") == 0) {
          analogWrite(redPin, red);
          analogWrite(greenPin, green);
          analogWrite(bluePin, blue);
          Serial.println("LED turned ON.");
        } else {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          Serial.println("LED turned OFF.");
        }
      } else {
        Serial.println("Failed to parse JSON");
      }
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
  delay(20000); // Send request every 20 seconds
}