#include "LEDControl.h"

// Define GPIO pins for the first RGB LED
const int redPin1 = D1;
const int greenPin1 = D2;
const int bluePin1 = D3;

// Define GPIO pins for the second RGB LED
const int redPin2 = D4;
const int greenPin2 = D5;
const int bluePin2 = D6;

// Initializes both RGB LEDs to the OFF state
void setupLEDs() {
    pinMode(redPin1, OUTPUT);
    pinMode(greenPin1, OUTPUT);
    pinMode(bluePin1, OUTPUT);
    pinMode(redPin2, OUTPUT);
    pinMode(greenPin2, OUTPUT);
    pinMode(bluePin2, OUTPUT);

    turnOffLED(1); // Start LED 1 off
    turnOffLED(2); // Start LED 2 off
}

// Sets the color for a specific LED based on the ledNumber (1 or 2)
void setLEDColor(int red, int green, int blue, int ledNumber) {
    if (ledNumber == 1) {
        analogWrite(redPin1, red);
        analogWrite(greenPin1, green);
        analogWrite(bluePin1, blue);
    } else if (ledNumber == 2) {
        analogWrite(redPin2, red);
        analogWrite(greenPin2, green);
        analogWrite(bluePin2, blue);
    }
}

// Turns off the specified LED by setting all its channels to 0
void turnOffLED(int ledNumber) {
    if (ledNumber == 1) {
        analogWrite(redPin1, 0);
        analogWrite(greenPin1, 0);
        analogWrite(bluePin1, 0);
    } else if (ledNumber == 2) {
        analogWrite(redPin2, 0);
        analogWrite(greenPin2, 0);
        analogWrite(bluePin2, 0);
    }
}
