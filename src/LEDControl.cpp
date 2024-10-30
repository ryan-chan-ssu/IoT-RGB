#include "LEDControl.h"

// Define GPIO pins for RGB LED
const int redPin = D1;
const int greenPin = D2;
const int bluePin = D3;

// Set RGB pins as outputs
void setupLED() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    turnOffLED(); // Start with the LED off
}

// Sets the LED color based on RGB values
void setLEDColor(int red, int green, int blue) {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

// Turns off the RGB LED by setting all channels to 0
void turnOffLED() {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}
