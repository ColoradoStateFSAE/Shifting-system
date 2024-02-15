#include "Clutch.h"

Clutch::Clutch(FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_64> &canRef, Storage &storageRef) :
	fsm(ANALOG_INPUT), can(canRef), storage(storageRef) {

	}

void Clutch::begin(int pin) {
	servo.attach(pin);
	servo.writeMicroseconds(storage.start());
}

void Clutch::writeMicroseconds(int value) {
	value = constrain(value, storage.end(), storage.start());
	servoPosition = value;
	servo.writeMicroseconds(value);
}

int Clutch::position() {
	return servoPosition;
}

int Clutch::percentage() {
	float normalizedValue = (float)(servoPosition - storage.start()) / (storage.end() - storage.start());
	normalizedValue = round(normalizedValue * 100);
	return normalizedValue;
}

void Clutch::update() {
	if(!storage.autoLaunch()) fsm.state(State::ANALOG_INPUT);
	if(storage.autoLaunch() && 90 <= input) fsm.state(State::HOLD_END);

	switch(fsm.state()) {
		case ANALOG_INPUT: {
			int servoWrite = map(input, 0.0f, 100.0f, storage.start(), storage.end());
			writeMicroseconds(servoWrite);
			break;
		}

		case HOLD_END: {
			autoLaunchPosition = storage.end();
			writeMicroseconds(autoLaunchPosition);

			if(input <= 50) {
				fsm.state(GOTO_FRICTION);
			}
			break;
		}

		case GOTO_FRICTION: {
			fsm.runOnce([&](){
				autoLanchStartTime = millis();
				Serial.println("\nGOTO FRICTION: " + String(millis() - autoLanchStartTime));
			});

			if(!fsm.incrementOverTime(autoLaunchPosition, storage.friction(), 200)) {
				fsm.state(HOLD_FRICTION);
			}
			writeMicroseconds(autoLaunchPosition);

			break;
		}

		case HOLD_FRICTION: {
			fsm.runOnce([&](){
				Serial.println("HOLD FRICTION: " + String(millis() - autoLanchStartTime));
			});

			fsm.waitAndSetState(500, [](){
				// Wait 500 ms
			}, GOTO_START);
			break;
		}

		case GOTO_START: {
			fsm.runOnce([&](){
				Serial.println("GOTO START: " + String(millis() - autoLanchStartTime));
			});

			if(!fsm.incrementOverTime(autoLaunchPosition, storage.start(), 500)) {
				Serial.println("REACHED START: " + String(millis() - autoLanchStartTime));
				fsm.state(ANALOG_INPUT);
			}
			writeMicroseconds(autoLaunchPosition);

			break;
		}
	}
}
