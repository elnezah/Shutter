#include <Arduino.h>
#include "Shutter.h"

/**
 Shutter.cpp - A library to control a servo as a button presser.
 The main purpose is to use a servo as a photocamera shutter.
 Has the capability to configure the pressed position, released position,
 shut, and configure a burst shot (number of repetitions and pause in between).
 @author elnezah@gmail.com
 */

/** Create a Shutter
 * Creates a simple shutter with standard values inside attached to the indicated servo
 *
 * @param *servo
 * A pointer to the servo you want the Shutter to activate.
 */
Shutter::Shutter(Servo *servo) {
	_servo = servo;
	_pressedPosition = 90;
	_releasedPosition = 90;
	_pressTime = 500;
	_repetitions = 1;
	_waitTime = 1000;
}

/** Sets the pressed position of the shutter.
 * The pressed position is the position (angle) where the servo actually
 * presses the physical button.
 *
 * @param pos
 * The angle in degrees (0-180)
 *
 */
void Shutter::setPressedPosition(int pos) {
	pos = (pos >= 0) ? pos : 0;
	pos = (pos <= 180) ? pos : 180;
	_pressedPosition = pos;
}

/** Sets the released position of the shutter.
 * The pressed position is the position (angle) where the servo actually
 * releases the physical button.
 *
 * @param pos
 * The angle in degrees (0-180)
 *
 */
void Shutter::setReleasedPosition(int pos) {
	pos = (pos >= 0) ? pos : 0;
	pos = (pos <= 180) ? pos : 180;
	_releasedPosition = pos;
}

/** Set the time the servo keeps the button pressed before releasing it.
 *
 * After the servo presses the button, it will wait a number of milliseconds before
 * releasing it again. Adjust this value here.
 *
 * @param pTime
 * The time in milliseconds (1-5000)
 *
 */
void Shutter::setPressTime(int pTime) {
	pTime = (pTime >= 0) ? pTime : 0;
	pTime = (pTime <= 5000) ? pTime : 5000;
	_pressTime = pTime;
}

/** Set the number of repetitions to be executed in a burst.
 *
 * @param reps
 * The number of repetitions (1 - 10000)
 */
void Shutter::setRepetitions(int reps) {
	reps = (reps > 0) ? reps : 1;
	reps = (reps <= 10000) ? reps : 10000;
	_repetitions = reps;
}

/** Sets the time to wait between repetitions in a burst
 *
 * @param waitTime
 * The time to wait in milliseconds (1-3600000)
 */
void Shutter::setWaitTime(int waitTime) {
	waitTime = (waitTime > 0) ? waitTime : 1;
	waitTime = (waitTime < 3600) ? waitTime : 3600000;
	_waitTime = waitTime;
}

/** Returns the pressed position the shutter is configured at
 */
int Shutter::getPressedPosition() {
	return _pressedPosition;
}

/** Returns the released position the shutter is configured at
 */
int Shutter::getReleasedPosition() {
	return _releasedPosition;
}

/** Returns the pressed time the shutter is configured at
 */
int Shutter::getPressTime() {
	return _pressTime;
}

/** Returns the number of repetitions the shutter is configured at
 */
int Shutter::getRepetitions() {
	return _repetitions;
}

/** Returns the wait time the shutter is configured at
 */
int Shutter::getWaitTime() {
	return _waitTime;
}

/** Returns a pointer to the servo the Shutter is controlling
 *
 */
Servo *Shutter::getServo() const {
	return _servo;
}

/** Execute one shot according to the values the shutter has
 *
 */
void Shutter::shutOnce() {
	_servo->write(_pressedPosition);
	delay(_pressTime);
	_servo->write(_releasedPosition);
}

/** Execute one burst according to the values the shutter has
 *
 */
void Shutter::doBurst() {
	for (int i = 0; i < _repetitions; i++) {
		shutOnce();
		delay(_waitTime);
	}
}
