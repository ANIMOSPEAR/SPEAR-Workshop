// Include the Servo Motor library
#include <Servo.h>

// Define constant values for servo motor rotations
#define North 180
#define West 0
#define East 90

// Initialized the servo motor named "Compass"
Servo Compass;

// Function to set the servo to a given angle (position)
void Compass_direction(int position) {
  Compass.write(position);
}

void setup() {
  // Attached the servo motor to pin 9
  Compass.attach(9);
}

void loop() {
  Compass_direction(North);
  delay(1000);
  Compass_direction(East);
  delay(1000);
  Compass_direction(West);
  delay(1000);
}
