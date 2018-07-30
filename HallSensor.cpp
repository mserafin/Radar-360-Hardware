#include "HallSensor.h"

void HallSensor::begin(
    unsigned int pin,
    void (*handleInterrupt)(void),
    void (*callback)(float diffTime, unsigned long lastTime))
{
  onChange = callback;
  pinMode(pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(pin), handleInterrupt, FALLING);
}

void HallSensor::refresh()
{
  unsigned long currentMillis = millis();
  story.diffTime = (float)(currentMillis - story.lastTime) / 1000;
  story.lastTime = currentMillis;
  onChange(story.diffTime, story.lastTime);
}
