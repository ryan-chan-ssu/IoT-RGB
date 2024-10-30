#ifndef WIFISETUP_H
#define WIFISETUP_H

#include <ESP8266WiFi.h>

// WiFi credentials
extern const char* ssid;
extern const char* password;

// Function prototype
void connectToWiFi();

#endif