﻿#pragma once
#include "Arduino.h"
#include "Adafruit_BNO055.h"

class EventData {
public:
	virtual ~EventData() = 0;
};
inline EventData::~EventData() {}

struct Time : EventData {
	byte Hours = 0;
	byte Minutes = 0;
	byte Seconds = 0;
	byte Tenths = 0;
};
struct DoorOpen_Data : EventData
{
	Time door_open_start;
	Time door_open_finish;
	
};
struct DoorClose_Data : EventData
{
	Time door_close_start;
	Time door_close_finish;
	
};

struct DOOR_DATA : EventData
{
	int door_to_open = 0;
	int door_to_close = 0;
};
struct bno_logger_data : EventData {
	imu::Vector<3> Gyro;
	imu::Vector<3> Mag;
	imu::Vector<3> Grav;
	uint8_t Temp;
	imu::Vector<3> Accel;
	imu::Vector<3> Euler;
	imu::Quaternion Quat;
	imu::Vector<3> linearAccel;
};
struct bno_temp_args : EventData {
	uint8_t Temp;
};
struct gravitometer_args : EventData {
	imu::Vector<3> Grav;
};
struct gyro_data : EventData {
	imu::Vector<3> Gyro;
};
struct position_args : EventData {
	imu::Vector<3> Euler;
	imu::Quaternion Quat;
};
struct magnetometer_args : EventData {
	imu::Vector<3> Mag;
};
struct accelerometer_args : EventData {
	imu::Vector<3> Accel;
	imu::Vector<3> linearAccel;
};
struct altitude_args :EventData {
	float Pressure;
	float Temp;
	float Altitude;
};
//struct bmp_alt_args :EventData {
//	float Pressure;
//	float Altitude;
//};

struct externalTemp_args : EventData {
	int8_t EXT_Temp;
};

struct temperature_args : EventData
{
	float BNO_Temp;
	float BMP_Temp;
	float AVG_temp;
};