// 
// 
// 

#include "pwm_lib.h"

PwmLib::PwmLib()
{
	servo = Servo();
}

void PwmLib::attachMotor(const int pin)
{
	pwmPin = pin;
	servo.attach(pwmPin);
}

//between -100 and 100
void PwmLib::set_value(int value)
{
	currentValue = getServoValue(value);
	servo.write(value);
}

int PwmLib::getServoValue(int value)
{
	int servoValue = 90;
	if ((100 < value))
	{
		value = 100;
	}
	else if (-100 > value)
	{
		value = -100;
	}

	if (0 == value)
	{
		servoValue = 58;
	}
	else if (0 < value)
	{
		servoValue = (value * 120) / 100) + 58;
		//interpolate to 1500 - 200
	}
	else if (0 > value)
	{
		//interpolate 1000 - 1500
		servoValue = ((value * 58) / 100) * (-1) ;
	}
	return servoValue;
}

