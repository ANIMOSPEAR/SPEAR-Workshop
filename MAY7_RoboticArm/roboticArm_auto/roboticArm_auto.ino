// Include the Servo Motor library
#include <Servo.h>

// Initialized the robotic arm joints (servo motors)
Servo servo_1;
Servo servo_2;
Servo servo_3;

void setup() {
  // Attached the joints (servo motors) to PWM pins
  servo_1.attach(5);
  servo_2.attach(6);
  servo_3.attach(9);
}

void loop() {
  // Move all servos to their starting position
  servo_1.write(0);  // set to angle 0
  servo_2.write(0);  // set to angle 0
  servo_3.write(0);  // set to angle 0
  delay(1500);

  // Move servos to a different position
  servo_1.write(60);  // set to angle 60
  servo_2.write(90);  // set to angle 90
  servo_3.write(180);  // set to angle 180
  delay(1500);
}
