// Define pins
const int trigger = 9;
const int echo = 10;

// Define variables
long duration;
long distance;

void setup() {
  // Intialize serial communication 
  Serial.begin(9600);
  
  pinMode(trigger, OUTPUT);  // set the trigger pin as an output
  pinMode(echo, INPUT);  // set the echo pin as an input
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(2);

  // Sends a 10ms pulse to trigger the sensor
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);

  // Measures the duration of the echo signal
  duration = pulseIn(echo, HIGH);

  // Calculate the distance
  distance = duration * 0.0343 / 2;

  // Print the calculated distance
  Serial.print("Distance: ");
  Serial.println(distance);
}
