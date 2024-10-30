#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>

// Define GPIO pins for RGB LED
extern const int redPin;
extern const int greenPin;
extern const int bluePin;

// Function prototypes
void setupLED(); // Initializes the LED pins
void setLEDColor(int red, int green, int blue); // Sets RGB values
void turnOffLED();

#endif