/*
 * -----------------------------------------------------------------------------------------------
 * Project/Program Name : RGB LED
 * File Name            : main.cpp
 * Author               : Ryan Chan
 * Date                 : 28/10/2024
 * Version              : 1.0
 * 
 * Purpose:
 *    This program allows user to remotely set the colors of the RGB LED connected to the ESP8266 
 *    microcontroller. The ESP sends request to the server every 20 seconds to read "results.txt"
 *    and adjust the LED state accordingly.
 * ------------------------------------------------------------------------------------------------
 */

#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "LEDControl.h"
#include "WiFiSetup.h"

// Server URL for fetching LED status and color values
const char* serverUrl = "https://rckh.xyz/API_assignment/results.txt";

void setup() {
  Serial.begin(9600);
  Serial.println("");

  // Connect to WiFi
  connectToWiFi();
  // Initialize the RGB LED pins
  setupLED();         
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
      StaticJsonDocument<256> doc;
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        // Check status (on or off)
        const char* status = doc["Node1"]["LED1"]["status"];
        Serial.print("Status: ");
        Serial.println(status);
        
        // Retrieve RGB values from JSON
        int red = doc["Node1"]["LED1"]["red"];
        int green = doc["Node1"]["LED1"]["green"];
        int blue = doc["Node1"]["LED1"]["blue"];

        // Set LED color based on the status
        if (strcmp(status, "on") == 0) {
          setLEDColor(red, green, blue);
          Serial.println("LED turned ON.");
        } else {
          // Turn off the LED if status is "off"
          turnOffLED();
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