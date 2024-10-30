#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>

// Define GPIO pins for the first RGB LED
extern const int redPin1;
extern const int greenPin1;
extern const int bluePin1;

// Define GPIO pins for the second RGB LED
extern const int redPin2;
extern const int greenPin2;
extern const int bluePin2;

// Function prototypes
void setupLEDs(); // Initialize both RGB LED pins
void setLEDColor(int red, int green, int blue, int ledNumber); // Sets RGB values for a specific LED
void turnOffLED(int ledNumber);
#endif
