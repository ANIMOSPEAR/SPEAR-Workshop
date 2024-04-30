// Include the Servo Motor library
#include <Servo.h>

// Define constant values for servo motor rotations
#define North 180
#define West 0
#define East 90

// Initialized the servo motors
Servo Compass1;
Servo Compass2;

// Functions to set the servo to a given angle (position)
void Compass1_direction(int position) {
  Compass1.write(position);
}

void Compass2_direction(int position) {
  Compass2.write(position);
}

void setup() {
  // Attached the servo motors to their pins
  Compass1.attach(9);
  Compass2.attach(10);
}

void loop() {
  Compass1_direction(North);
  Compass2_direction(North);
  delay(1000);
  Compass1_direction(West);
  Compass2_direction(West);
  delay(1000);
  Compass1_direction(East);
  Compass2_direction(East);
  delay(1000);
}
