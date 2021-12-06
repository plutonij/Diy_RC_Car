/*
 Name:		projects.ino
 Created:	12/6/2021 7:01:24 AM
 Author:	matija
*/

#include "pwm_lib.h"
const int enginePin = 4;
const int steeringPin = 5;
// the setup function runs once when you press reset or power the board
PwmLib Steering = PwmLib();

int PwmValue = 0;
void setup() {
	Steering.attachMotor(enginePin);
}

// the loop function runs over and over again until power down or reset
void loop() {
	Serial.print("PwmValue =");
	Serial.println(PwmValue);
	Steering.set_value(PwmValue);
	delay(2000);
 
	
}
