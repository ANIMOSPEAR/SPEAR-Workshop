// Initialize right motors
const int PWM_right = 10;
const int motor_RB = 9;
const int motor_RF = 8;

// Initialize left motors
const int PWM_left = 5;
const int motor_LB = 6;
const int motor_LF = 7;

// Initialize variables
const int normforward_speed = 140;  // normal forward
const int slowforward_speed = 120;    // slow forward
const int backward_speed = 120;  // backward
const int pivotturn_speed = 125;  // pivot turn
const int turn_speed = 150;  // normal turn

void setup() {
  Serial.begin(9600);

  // Set motor pins as OUTPUT
  pinMode(motor_RF, OUTPUT);
  pinMode(motor_RB, OUTPUT);
  pinMode(motor_LF, OUTPUT);
  pinMode(motor_LB, OUTPUT);
}

void loop() {
  // Read values from IR sensors
  int IR_LL = digitalRead(A0);
  int IR_L = digitalRead(A1);
  int IR_C = digitalRead(A2); 
  int IR_R = digitalRead(A3);
  int IR_RR = digitalRead(A4);

  // Line following logic
  // 1 = White; 0 = Black

  // Center Sensor
  if (IR_C == 0) {
    if (IR_L == 1 && IR_R == 1) {
      forward();
    } else {
      slowforward();
    }
  }
  // Left Sensor
  else if (IR_LL == 0 || IR_L == 0) {
    if (IR_LL == 0 && IR_L == 1) {
      fastleft();
    } else if (IR_LL == 1 && IR_L == 0) {
      pivotleft();
    } else {
      pivotleft();
    }
  }
  // Right Sensor
  else if (IR_RR == 0 || IR_R == 0) {
    if (IR_RR == 0 && IR_R == 1) {
      fastright();
    } else if (IR_RR == 1 && IR_R == 0) {
      pivotright();
    } else {
      pivotright();
    }
  }
  // All white
  if (IR_LL == 1 && IR_L == 1 && IR_C == 1 && IR_R == 1 && IR_RR == 1) {
    backward();
  }

  // // Serial output for debugging
  // Serial.print("IR_LL: ");
  // Serial.print(IR_LL);
  // Serial.print(" IR_L: ");
  // Serial.print(IR_L);
  // Serial.print(" IR_C: ");
  // Serial.print(IR_C);
  // Serial.print(" IR_R: "); 
  // Serial.print(IR_R);
  // Serial.print(" IR_RR: "); 
  // Serial.println(IR_RR);
}

void stop() {
  // Stop all motors
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, LOW);

  // Set PWM values to 0
  analogWrite(PWM_right, 0);
  analogWrite(PWM_left, 0);
}

void forward() {
  // Move forward
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values for forward motion
  analogWrite(PWM_right, normforward_speed);
  analogWrite(PWM_left, normforward_speed);
}

void slowforward() {
  // Move forward
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values 
  analogWrite(PWM_right, slowforward_speed);
  analogWrite(PWM_left, slowforward_speed);
}

void backward() {
  // Move forward
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values 
  analogWrite(PWM_right, backward_speed);
  analogWrite(PWM_left, backward_speed);
}

void pivotleft() {
  // Turn pivot left
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, LOW);

  // Set PWM values 
  analogWrite(PWM_right, pivotturn_speed);
  analogWrite(PWM_left, pivotturn_speed);
}

void fastleft() {
  // Turn left
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  // Set PWM values 
  analogWrite(PWM_right, turn_speed);
  analogWrite(PWM_left, turn_speed);
}

void pivotright() {
  // Turn pivot right
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values 
  analogWrite(PWM_right, pivotturn_speed);
  analogWrite(PWM_left, pivotturn_speed);
}

void fastright() {
  // Turn right
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values 
  analogWrite(PWM_right, turn_speed);
  analogWrite(PWM_left, turn_speed);
}