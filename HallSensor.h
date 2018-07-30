#pragma once
#include "Arduino.h"

class HallSensor
{
public:
  void begin(
      unsigned int pin,
      void (*handleInterrupt)(void),
      void (*callback)(float diffTime, unsigned long lastTime));
  void refresh();

private:
  struct Store
  {
    float diffTime;
    unsigned long lastTime;
  } story;

  void (*onChange)(float diffTime, unsigned long lastTime);
};
