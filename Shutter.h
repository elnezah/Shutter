#ifndef SHUTTER_H
#define SHUTTER_H
#include "Servo.h"

/*
 * Shutter.h - Library to make a photocamera shutter out of a servo
 *   alternatively it could press any physical button with a servo.
 */

class Shutter {
  public:
    Shutter(Servo *servo);
    void setPressedPosition(int pos);
    void setReleasedPosition(int pos);
    void setPressTime(int pTime);
    void setRepetitions(int reps);
    void setWaitTime(int waitTime);
    
    int getPressedPosition();
    int getReleasedPosition();
    int getPressTime();
    int getRepetitions();
    int getWaitTime();
    Servo *getServo() const;
    
    void shutOnce();
    void doBurst();
  private:
    Servo *_servo;
    int _pressedPosition;
    int _releasedPosition;
    int _pressTime;
    int _repetitions;
    int _waitTime;   
};

#endif
