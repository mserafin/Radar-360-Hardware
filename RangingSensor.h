#pragma once
#include "Arduino.h"
#include "DistanceSensor.h"
#include "RangingSensor.h"
#include <Wire.h>
#include <VL53L0X.h>

//#define LONG_RANGE
#define HIGH_SPEED
//#define HIGH_ACCURACY

class RangingSensor : public DistanceSensor
{
public:
  void begin() override;
  int readRangeInMillimeters() override;

protected:
  VL53L0X sensor;
};
