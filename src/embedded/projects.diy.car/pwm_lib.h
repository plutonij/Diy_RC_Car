// pwm_lib.h

#ifndef _pwm_lib_h
#define _pwm_lib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Servo.h>


class PwmLib
{
 protected:


 public:
	 PwmLib();
	 void set_value(int value);
	 void attachMotor(const int pin);

private:
	int getServoValue(int value);
	int pwmPin;
	int currentValue;
	Servo servo;
};

#endif

