#pragma once
#include "Arduino.h"

class Calculation
{
public:
  float angularSpeed(float rotationTime);

  float linearSpeed(float angularSpeed, float radius);

  float angleInDegrees(float angularSpeed, unsigned long lastMillis);

  float angleInRadians(float angularSpeed, unsigned long lastMillis);

protected:
  float betweenThem(float value, float min = 0, float max = 360);
};
