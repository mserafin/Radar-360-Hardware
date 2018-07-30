#pragma once
#include "Arduino.h"

class SerialPort
{
public:
  struct Store
  {
    float angle;
    int distance;
    int distanceMax;
    float speed;
  } story;

  void begin(unsigned long speed);

  void send(Store data);
};
