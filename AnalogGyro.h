#ifndef ANALOG_GYRO_H
#define ANALOG_GYRO_H

#include <Arduino.h>

class AnalogGyro
{
public:
	AnalogGyro(uint8_t analog_pin);

	float get_angle();
	void reset_angle();

	void set_voltage_level(float voltage);
	void set_sensitivity(float volt_deg_sec);
	void set_minimum_threshold(float voltage);

	void update();

private:
	uint8_t analog_pin;

	float angle = 0.0;
	float voltage_level = 5.0;
	float zero_voltage = 2.5;
	float sensitivity = 0.007;
	float minimum_threshold = 5;
	uint32_t time_last_update = 0;
	
};

#endif