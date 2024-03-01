#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "Clutch/Clutch.h"
#include "Storage/Storage.h"
#include "FiniteStateMachine/FiniteStateMachine.h"
#include "Can/Can.h"

class Transmission {
  public:
  	enum Direction {
		UP,
		DOWN
	};

	enum State {
		IDLE,

		UP_SPARK_CUT,
		UP_ENABLE_SOLENOID,
		UP_DISABLE_SOLENOID,

		DOWN_CLUTCH_IN,
		DOWN_ENABLE_SOLENOID,
		DOWN_DISABLE_SOLENOID,
		DOWN_CLUTCH_OUT,
	};

	FiniteStateMachine fsm = FiniteStateMachine(IDLE);

	Transmission() = delete;
	Transmission(Clutch &clutchRef, Can &canRef, Storage &settingsRef);
	void shift(Transmission::Direction direction);
	void update();

  private:	
	Clutch &clutch;
	Can &can;
	Storage &storage;

	unsigned long shiftStartTime = 0;
	unsigned long lastBroadastTime = 0;

	void changeGear(Transmission::Direction direction);
	void disableCombustion();
	void upRoutine();
	void downRoutine();
};

#endif
