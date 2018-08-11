#include "L298.h"
#include "MechanumDrive.h"

L298 motor_a(9, 8);
L298 motor_b(5, 4);
L298 motor_c(6, 7);
L298 motor_d(10, 11);

MechanumDrive mech(motor_a, motor_b, motor_c, motor_d);

int counter = 0;


void setup()
{
	TCCR0B = TCCR0B & 0b11111000 | 0x01;
	TCCR1B = TCCR1B & 0b11111000 | 0x01;
	TCCR2B = TCCR2B & 0b11111000 | 0x01;
}

void loop()
{
	// cos(counter / 100.0) * 25.0
	mech.set(sin(counter / 100.0) * 35.0 , cos(counter / 100.0) * 35.0 , 0.0);
	delay(400);
	counter++;
}