// Include the Servo Motor library
#include <Servo.h>

// Initialized the robotic arm joints (servo motors)
Servo servo_1;
Servo servo_2;  
Servo servo_3;  

// Initialize the potentiometer pins by attaching them to analog pins
int control_1 = A0;
int control_2 = A1; 
int control_3 = A2; 

// Variables to store the analog readings from potentiometers
int value_1;
int value_2;
int value_3;

void setup() {
  // Attached the joints (servo motors) to PWM pins
  servo_1.attach(5);
  servo_2.attach(6);
  servo_3.attach(9);
}

void loop() {
  // Read the analog value from potentiometer
  value_1 = analogRead(control_1);  

  // Convert the range of the analog value (0 to 1023) to servo motor range (0 to 180)
  value_1 = map(value_1, 0, 1023, 0, 180); 

  // Set servo motor angle based on the mapped value
  servo_1.write(value_1); 


  // **same code explanation from above
  // Read analog values from potentiometer and map them to servo angles
  value_2 = analogRead(control_2); 
  value_2 = map(value_2, 0, 1023, 0, 180);
  servo_2.write(value_2);

  // **same code explanation from above
  // Read analog values from potentiometer and map them to servo angles
  value_3 = analogRead(control_3);
  value_3 = map(value_3, 0, 1023, 0, 180); 
  servo_3.write(value_3);
}