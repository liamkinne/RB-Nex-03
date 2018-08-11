#ifndef L298_H
#define L298_H

#include <Arduino.h>

class L298
{
public:
	L298(uint8_t pin_pwm, uint8_t pin_direction);

	void set(float velocity);

	void set_inverted(bool inverted);
private:
	const uint8_t pin_pwm, pin_direction; 

	bool is_inverted = false;
	
};

#endif