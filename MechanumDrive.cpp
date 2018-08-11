#include "MechanumDrive.h"

MechanumDrive::MechanumDrive(L298 motor_a, L298 motor_b, L298 motor_c, L298 motor_d):
	motor_a(motor_a),
	motor_b(motor_b),
	motor_c(motor_c),
	motor_d(motor_d)
{

}

void MechanumDrive::set(float linear_x, float linear_y, float angular_z)
{
	float wheel_front_left 	= (1/wheel_radius) * (linear_x - linear_y - (wheel_separation.width + wheel_separation.length) * angular_z);
	float wheel_front_right = (1/wheel_radius) * (linear_x + linear_y + (wheel_separation.width + wheel_separation.length) * angular_z);
	float wheel_rear_left 	= (1/wheel_radius) * (linear_x + linear_y - (wheel_separation.width + wheel_separation.length) * angular_z);
	float wheel_rear_right 	= (1/wheel_radius) * (linear_x - linear_y + (wheel_separation.width + wheel_separation.length) * angular_z);

	motor_b.set(wheel_front_left);
	motor_a.set(-wheel_front_right);
	motor_c.set(wheel_rear_left);
	motor_d.set(-wheel_rear_right);

}