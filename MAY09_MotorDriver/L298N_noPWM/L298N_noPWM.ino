// Initialize pins for motor control
#define in1 2
#define in2 3
#define in3 4
#define in4 5

void setup() {
  // Set pin modes as output
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
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// Move both motors forward
void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Move both motors backward
void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Move right motor backward and left motor forward
void turnright() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Move right motor forward and left motor backward
void turnleft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}