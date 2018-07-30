#include "RangingSensor.h"

void RangingSensor::begin()
{
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);
  //sensor.startContinuous();

#if defined LONG_RANGE
  sensor.setSignalRateLimit(0.1);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
  sensor.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  sensor.setMeasurementTimingBudget(200000);
#endif
}

int RangingSensor::readRangeInMillimeters()
{
  //return sensor.readRangeContinuousMillimeters();
  return sensor.readRangeSingleMillimeters();
}
