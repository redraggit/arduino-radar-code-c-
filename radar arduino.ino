// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  myServo.attach(12); // Attach the servo to pin 12
}

void loop() {
  // Move servo from 45 to 135 degrees
  for (int angle = 45; angle <= 135; angle++) {
    myServo.write(angle);
    delay(15); // Adjust this delay for speed control
  }

  // Move servo from 135 to 45 degrees
  for (int angle = 135; angle >= 45; angle--) {
    myServo.write(angle);
    delay(15); // Adjust this delay for speed control
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}