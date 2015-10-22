﻿#include "arduino_mega.h"
#include "heater_actions.h"
#include "sensor_actions.h"
#include "logging_actions.h"
#include "Doorman_Actions.h"
#include "EventHandler.h"

#include <avr/pgmspace.h>
#include <RTClib.h>


arduino_mega::arduino_mega() 
			: _logger(this), _onboardLED(LED(4)), _extTempSensor(&_OneWireBus), 
			_bnoSensor(0x28), _bmpSensor(0x55), _humidSensor(0x27), _OneWireBus(OneWire(2)){
	
	//start bno055 
	if (!_bnoSensor.begin()) {
		Serial.print(F("9dof sensor not detected..."));
		while (1);
	}
	//start bmp180
	if (!_bmpSensor.begin()) {
		Serial.print(F("bmp180 not detected..."));
		while (1);
	}
	//start humid sensor
	_humidSensor.begin();

	//start external temp sensor
	_extTempSensor.begin();
	
	_bnoSensor.setExtCrystalUse(true);
	EVENTHANDLER.add_eventAction(".2s", new sensor_update(_bnoSensor, _bmpSensor, _extTempSensor, _humidSensor));
	EVENTHANDLER.add_eventAction("sensor_update", new log_all_data(_logger));
	
	EVENTHANDLER.add_eventAction(".1s", new doorman_altitude_check(_bmpSensor, this));
		
	EVENTHANDLER.add_eventAction("5s", new avg_temp_update(_bmpSensor,_bnoSensor,_humidSensor));
	EVENTHANDLER.add_eventAction("avg_temp_update", new update_heater_status);

	
}

DateTime arduino_mega::getTime() const {
	return _realTimeClock.now();
}


/*
Todo:

Add in led support for calibrating the accel/gyro/fusion/magnetometer
First i wanna set up 4 leds
Turn them off to start, then when poweredm, turn to red if non calibrated
if calibration level increases, change the color of the led to yellow, then to green


*/