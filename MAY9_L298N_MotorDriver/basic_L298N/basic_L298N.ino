// Initialize pins for motor control
#define ena 11
#define enb 10
#define in1 2
#define in2 3
#define in3 4
#define in4 5

void setup() {
  // Set pin modes as output
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // *INSERT MOVE FUNCTION
  delay(1000);

  // *INSERT MOVE FUNCTION
  delay(1000);

  // *INSERT MOVE FUNCTION
  delay(1000);

  // *INSERT MOVE FUNCTION
  delay(1000);
}

// Stop both motors
void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(ena, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enb, 0);
}

// Move both motors forward
void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 255);
}

// Move both motors backward
void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 255);
}

// Move right motor backward and left motor forward
void turnright() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enb, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 150);
}

// Move right motor forward and left motor backward
void turnleft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enb, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 150);
}