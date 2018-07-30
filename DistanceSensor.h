#pragma once

class DistanceSensor
{
public:
  virtual void begin();
  virtual int readRangeInMillimeters() = 0;
};
