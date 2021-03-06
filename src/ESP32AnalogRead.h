/*
 * ESP32AnalogRead.h
 *
 *  Created on: Apr 10, 2020
 *      Author: hephaestus
 *      https://github.com/madhephaestus/ESPMutexDemo/blob/DSPTest/ESPMutexDemo.ino
 *
 *  Modified by Alessandro Curzi to add multisampling on: Feb 19, 2022
 *
 */

#pragma once
#include <Arduino.h>
#include "esp_adc_cal.h"
#define V_REF 1100 // ADC reference voltage
#define NO_OF_SAMPLES 64 // number of samples for multisampling.


class ESP32AnalogRead
{
private:
	int myPin = 0;
	esp_adc_cal_characteristics_t characteristics;
	adc_channel_t channel;
	adc1_channel_t adc1_channel;
	adc2_channel_t adc2_channel;
	adc_unit_t unit;
	boolean attached = false;

public:
	ESP32AnalogRead(int pin = -1);
	~ESP32AnalogRead() {}
	void attach(int pin);
	void checkEfuse(void);
	float readVoltage();
	uint32_t readMiliVolts();
};
