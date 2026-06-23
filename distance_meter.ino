/*
   Ultrasonic Distance Meter — HC-SR04
   Measures distance in centimeters and prints to Serial Monitor.
   The simplest possible ultrasonic sensor example.

   Connections:
   - VCC  → Arduino 5V
   - GND  → Arduino GND
   - Trig → Arduino pin 9
   - Echo → Arduino pin 10

   How it works:
   Trig sends a short pulse. The sensor emits ultrasonic sound.
   Echo goes HIGH and stays HIGH until the sound bounces back.
   pulseIn() measures how long Echo stayed HIGH.
   Distance = (time * speed of sound) / 2

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

const int trigPin = 9;
const int echoPin = 10;

// Speed of sound in cm per microsecond at room temperature
// Changes slightly with temperature and humidity, but 0.034 is close enough
const float soundSpeed = 0.034;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);  // Trig sends the pulse OUT
  pinMode(echoPin, INPUT);   // Echo reads the returning pulse IN

  Serial.println("Ultrasonic Distance Meter Ready");
  Serial.println("================================");
  Serial.println("Point the sensor at something and watch the readings.");
}

void loop() {
  // Step 1: Clear the Trig pin briefly
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Step 2: Send a 10-microsecond HIGH pulse
  // This tells the sensor to send out 8 bursts of 40kHz sound
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Step 3: Measure how long Echo stays HIGH
  // pulseIn() waits for the pin to go HIGH, then returns the time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Step 4: Convert time to distance
  // Divide by 2 because the sound travels to the object AND back
  float distanceCm = (duration * soundSpeed) / 2.0;

  // Step 5: Print the result
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Small delay before the next reading
  // If you make this too short, readings become unstable
  delay(500);
}
