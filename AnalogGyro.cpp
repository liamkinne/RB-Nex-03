#include "AnalogGyro.h"

AnalogGyro::AnalogGyro(uint8_t analog_pin):
	analog_pin(analog_pin)
{

}

float AnalogGyro::get_angle()
{
	return angle;
}

void AnalogGyro::reset_angle()
{
	angle = 0.0;
}

void AnalogGyro::set_voltage_level(float voltage)
{
	voltage_level = voltage;
}

void AnalogGyro::set_sensitivity(float volt_deg_sec)
{
	sensitivity = volt_deg_sec;
}


void AnalogGyro::set_minimum_threshold(float deg_sec)
{
	minimum_threshold = deg_sec;
}

void AnalogGyro::update()
{
	float rate = (analogRead(analog_pin) * voltage_level) / 1023;

	rate -= zero_voltage;

	rate /= sensitivity;

	if (fabs(rate) >= minimum_threshold)
	{
		uint32_t time_delta = (millis()/64) - time_last_update;
		rate /= 1000 / time_delta;
		angle += rate;
	}


	time_last_update = millis()/64;
}