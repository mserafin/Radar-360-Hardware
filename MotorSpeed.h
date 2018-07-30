#pragma once
#include "Arduino.h"

class MotorSpeed
{
public:
  void begin(unsigned int motorPin, unsigned int speedPin);
  void refresh();

private:
  unsigned int motorPin;
  unsigned int speedPin;
  int readSpeed();
};
