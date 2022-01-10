
#include <MPU6050_tockn.h>
#include <Wire.h>

#define PWMa 14
#define PWMb 27
#define PWMc 26
#define PWMd 25

int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;

void setup() {
  // rotary encoder pins
  pinMode(PWMa, OUTPUT);
  pinMode(PWMb, OUTPUT);
  pinMode(PWMc, OUTPUT);
  pinMode(PWMd, OUTPUT);

  Serial.begin(9600);                 // pins for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
                              //code for ultrasonic sensor to calculate distance from object
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  
  // duration is the time (in microseconds)
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  
  delay (2000);                //commands for the code
  
  // forwards
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, HIGH);
  digitalWrite(PWMc, HIGH);
  digitalWrite(PWMd, LOW);

                             //drive foward for 1 second
  delay (1000); 


  // turn 180 degrees
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, HIGH);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, HIGH);
  
  delay (800);                                    //EDIT TO FIND OUT WHEN ITS 180 DEGREES

  // drive backwards
  digitalWrite(PWMa, HIGH);
  digitalWrite(PWMb, LOW);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, HIGH);

  if (cm <= 10) {         //when distance is less than 10cm, stop vehicle
  // stop vehicle
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, LOW);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, LOW);

  delay (2000);           //after 2 secs
  }

  // turn 90 degrees                          //turn 90 degrees??? CHECK DIRECTION AND EDIT
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, HIGH);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, HIGH);

  delay (400);                                             //EDIT UNTIL TURNS 90 DEGREES  

  // drive backwards
  digitalWrite(PWMa, HIGH);
  digitalWrite(PWMb, LOW);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, HIGH);


  if (cm <= 10) {             //if distance is less than 10cm, stop vehicle
  // stop vehicle
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, LOW);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, LOW);
  }

}
