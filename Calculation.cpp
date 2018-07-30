#include "Calculation.h"

float Calculation::angularSpeed(float rotationTime)
{
  return (float)(2 * PI) / rotationTime;
}

float Calculation::linearSpeed(float angularSpeed, float radius)
{
  return (float)angularSpeed * radius;
}

float Calculation::angleInRadians(float angularSpeed, unsigned long lastMillis)
{
  float diffTime = (float)(millis() - lastMillis) / 1000;
  return angularSpeed * diffTime;
}

float Calculation::angleInDegrees(float angularSpeed, unsigned long lastMillis)
{
  float radians = this->angleInRadians(angularSpeed, lastMillis);
  return this->betweenThem(round(180 * (radians / PI)));
}

float Calculation::betweenThem(float value, float min = 0, float max = 360)
{
  if (value < min)
    return 0;

  if (value > max)
    return 360;

  return value;
}
