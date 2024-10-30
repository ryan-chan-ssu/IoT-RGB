#include "WiFiSetup.h"

// Define WiFi credentials
const char* ssid = "Loading...";
const char* password = "Finexes0621";

// Connect to WiFi
void connectToWiFi() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    
    // Loop until connected
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);  // Wait 1 second between connection attempts
        Serial.print(".");
    }
    
    // Confirm successful connection
    Serial.println("\nWiFi Connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}