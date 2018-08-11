#include "L298.h"

L298::L298(uint8_t pin_pwm, uint8_t pin_direction):
	pin_pwm(pin_pwm),
	pin_direction(pin_direction)
{
	pinMode(pin_pwm, OUTPUT);
	pinMode(pin_direction, OUTPUT);
}

void L298::set(float velocity)
{
	analogWrite(pin_pwm, fabs(velocity) * 255);
	digitalWrite(pin_direction, is_inverted ? velocity < 0: velocity > 0);
}

void L298::set_inverted(bool inverted)
{
	is_inverted = inverted;
}