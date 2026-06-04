/*
   Ultrasonic Distance Meter
   The simplest possible HC-SR04 example.
   Reads distance in centimeters and prints to Serial Monitor.

   Hardware:
     - Arduino Uno R3
     - HC-SR04 ultrasonic sensor
     - 4 jumper wires

   Connections:
     VCC -> 5V
     GND -> GND
     Trig -> pin 9
     Echo -> pin 10

   Created by Parham (inquiline), 2026.
   License: MIT
*/

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;

// Speed of sound in cm per microsecond (at room temperature)
const float soundSpeed = 0.034;

void setup() {
  // Start serial communication so we can see the result on the computer
  Serial.begin(9600);

  // Set the Trig pin as OUTPUT (we send a pulse from here)
  pinMode(trigPin, OUTPUT);
  
  // Set the Echo pin as INPUT (we read the returning pulse here)
  pinMode(echoPin, INPUT);

  Serial.println("Ultrasonic Distance Meter Ready");
  Serial.println("================================");
}

void loop() {
  // 1. Clear the Trig pin by setting it LOW for 2 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. Send a 10-microsecond HIGH pulse to Trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. Read the Echo pin and measure how long it stays HIGH
  long duration = pulseIn(echoPin, HIGH);

  // 4. Calculate the distance
  //    distance = (duration * speed of sound) / 2
  //    (divided by 2 because the sound travels to the object AND back)
  float distanceCm = (duration * soundSpeed) / 2.0;

  // 5. Print the result
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Wait a little before the next reading
  delay(500);
}
