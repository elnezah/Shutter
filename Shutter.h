/*
 * Shutter.h - Library to make a photocamera shutter out of a servo
 *   alternatively it could press any physical button with a servo.
 */


#ifndef Shutter
#define Shutter

#include "Arduino.h"
#include "Servo.h"

class Shutter {
  public:
    Shutter(Servo servo);
    void setPressedPosition(int pos);
    void setReleasedPosition(int pos);
    void setPressTime(int pTime);
    void shut();
    Servo getServo();
  private:
    Servo _servo;
    int _pressedPosition;
    int _releasedPosition;
    int _pressTime;
    
}

#endif
