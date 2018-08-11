#ifndef MECHANUM_DRIVE_H
#define MECHANUM_DRIVE_H

#include <Arduino.h>
#include "L298.h"

class MechanumDrive
{
public:
	MechanumDrive(L298 motor_a, L298 motor_b, L298 motor_c, L298 motor_d);
	
	void set(float linear_x, float linear_y, float angular_x);

private:
	L298 motor_a, motor_b, motor_c, motor_d;

	struct {
		float width = 6 * 25.4;
		float length = 6 * 25.4;
	} wheel_separation;

	const float wheel_radius = 2 * 25.4;
	
};

#endif