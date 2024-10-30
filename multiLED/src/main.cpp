/*
 * -----------------------------------------------------------------------------------------------
 * Project/Program Name : RGB LED
 * File Name            : main.cpp
 * Author               : Ryan Chan
 * Date                 : 28/10/2024
 * Version              : 1.0
 * 
 * Purpose:
 *    This program allows user to remotely set the colors of multiple RGB LEDs connected to the ESP8266 
 *    microcontroller. The ESP sends request to the server every 20 seconds to read "results.txt"
 *    and adjust both LED states idependently.
 * ------------------------------------------------------------------------------------------------
 */

#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "LEDControl.h"
#include "WiFiSetup.h"

// Server URL for fetching LED status and color values
const char* serverUrl = "https://rckh.xyz/API_assignment/multiLED/results.txt";

void setup() {
    Serial.begin(9600);
    Serial.println("");
  
    // Connect to WiFi
    connectToWiFi();  
    // Initialize both RGB LEDs
    setupLEDs();
}

void loop() {
  // Check if WiFi is connected before making HTTP request
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    HTTPClient http;
    client.setInsecure();
    http.begin(client, serverUrl);

    // Send HTTP GET request
    int httpCode = http.GET();
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);

    if (httpCode == HTTP_CODE_OK) {
      // Get the JSON data as a string
      String payload = http.getString();
      Serial.println("Received payload: " + payload);

      // Parse the JSON input from results.txt
      StaticJsonDocument<512> doc;
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        // Control for LED 1
        const char* status1 = doc["Node1"]["LED1"]["status"];
        int red1 = doc["Node1"]["LED1"]["red"];
        int green1 = doc["Node1"]["LED1"]["green"];
        int blue1 = doc["Node1"]["LED1"]["blue"];

        if (strcmp(status1, "on") == 0) {
          setLEDColor(red1, green1, blue1, 1);
          Serial.println("LED 1 turned ON.");
        } else {
          turnOffLED(1);
          Serial.println("LED 1 turned OFF.");
        }

        // Control for LED 2
        const char* status2 = doc["Node1"]["LED2"]["status"];
        int red2 = doc["Node1"]["LED2"]["red"];
        int green2 = doc["Node1"]["LED2"]["green"];
        int blue2 = doc["Node1"]["LED2"]["blue"];

        if (strcmp(status2, "on") == 0) {
          setLEDColor(red2, green2, blue2, 2);
          Serial.println("LED 2 turned ON.");
        } else {
          turnOffLED(2);
          Serial.println("LED 2 turned OFF.");
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
