#include "SerialPort.h"

void SerialPort::begin(unsigned long speed)
{
  while (!Serial);
  Serial.begin(speed);
}

void SerialPort::send(Store story)
{
  Serial.print("{\"angle\":");
  Serial.print(story.angle);
  Serial.print(",");
  Serial.print("\"distance\":");
  Serial.print(story.distance);
  Serial.print(",");
  Serial.print("\"max\":");
  Serial.print(story.distanceMax);
  Serial.print(",");
  Serial.print("\"speed\":");
  Serial.print(story.speed);
  Serial.println("}");
}
