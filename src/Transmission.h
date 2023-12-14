#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <Arduino.h>
#include <EEPROM.h>
#include <FlexCAN_T4.h>
#include <TeensyTimerTool.h>
#include "canutil.h"
#include "Clutch.h"

using namespace TeensyTimerTool;

enum {
	UP = 0,
	DOWN = 1
};

class Transmission {
  public:
	Transmission() = delete;
	Transmission(Clutch &clutchRef, FlexCAN_T4<CAN3, RX_SIZE_16, TX_SIZE_16> &canRef) : clutch(clutchRef), can(canRef) {
		pinMode(OUTPUT_PINS[0], OUTPUT);
		pinMode(OUTPUT_PINS[1], OUTPUT);
		pinMode(13, OUTPUT);

		uint16_t saved;
		EEPROM.get(GEAR_ADDRESS, saved); if(saved == 0xFFFF) setGear(0);
		EEPROM.get(UP_DELAY_ADDRESS, saved); if(saved == 0xFFFF) setUpDelay(50);
		EEPROM.get(DOWN_DELAY_ADDRESS, saved); if(saved == 0xFFFF) setDownDelay(200);
		EEPROM.get(OUTPUT_ADDRESS, saved); if(saved == 0xFFFF) setOutput(50);
		EEPROM.get(TIMEOUT_ADDRESS, saved); if(saved == 0xFFFF) setTimeout(500);
	}

	void setGear(uint16_t value) { EEPROM.put(GEAR_ADDRESS, value); }
	uint16_t getGear() { uint16_t saved; EEPROM.get(GEAR_ADDRESS, saved); return saved; }

	void setUpDelay(uint16_t value) { EEPROM.put(UP_DELAY_ADDRESS, value); }
	uint16_t getUpDelay() { uint16_t saved; EEPROM.get(UP_DELAY_ADDRESS, saved); return saved; }

	void setDownDelay(uint16_t value) { EEPROM.put(DOWN_DELAY_ADDRESS, value); }
	uint16_t getDownDelay() { uint16_t saved; EEPROM.get(DOWN_DELAY_ADDRESS, saved); return saved; }

	void setOutput(uint16_t value) { EEPROM.put(OUTPUT_ADDRESS, value); }
	uint16_t getOutput() { uint16_t saved; EEPROM.get(OUTPUT_ADDRESS, saved); return saved; }

	void setTimeout(uint16_t value) { EEPROM.put(TIMEOUT_ADDRESS, value); }
	uint16_t getTimeout() { uint16_t saved; EEPROM.get(TIMEOUT_ADDRESS, saved); return saved; }

	void setRpm(int value) { rpm = value; }
	int getRpm() { return rpm; }

	void broadcast_gear(unsigned long frequency=0);
	void shift(int direction);

  private:
	const int OUTPUT_PINS[2] = {41, 40}; // {up, down}

	const int GEAR_ADDRESS = 0;
	const int UP_DELAY_ADDRESS = 2;
	const int DOWN_DELAY_ADDRESS = 4;
	const int OUTPUT_ADDRESS = 6;
	const int TIMEOUT_ADDRESS = 8;

	const int CLUTCH_DELAY = 500;

	Clutch &clutch;
	FlexCAN_T4<CAN3, RX_SIZE_16, TX_SIZE_16> &can;

	int rpm = 0;
	volatile bool timeout = false;
	unsigned long startTime = 0;

	void disable_combustion();
	void power_solenoid(int direction);
};

#endif