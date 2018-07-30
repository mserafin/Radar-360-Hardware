#include "MotorSpeed.h"

void MotorSpeed::begin(unsigned int motorPin, unsigned int speedPin)
{
  this->motorPin = motorPin;
  this->speedPin = speedPin;

  pinMode(this->motorPin, OUTPUT);
  pinMode(this->speedPin, INPUT_PULLUP);
}

int MotorSpeed::readSpeed()
{
  return map(analogRead(this->speedPin), 0, 1023, 0, 255);
}

void MotorSpeed::refresh()
{
  int value = readSpeed();
  analogWrite(this->motorPin, value);
}
