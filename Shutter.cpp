/*
  Shutter.cpp - Library for flashing Shutter code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Shutter.h"

Shutter::Shutter(Servo servo)
{
    _servo = servo;
}


void Shutter::setPressedPosition(int pos) {
    _pressedPosition = pos;
}

void setReleasedPosition(int pos) {
    _releasedPosition = pos;
}

void setPressTime(int pTime) {
    _pressTime = pTime;
}

void shut() {
    servo.write(_pressedPosition);
    delay(_pressTime);
    servo.write(_releasedPosition);
}

Servo getServo() {
    return _servo;
}
