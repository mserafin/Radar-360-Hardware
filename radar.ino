#include "RangingSensor.h"
#include "HallSensor.h"
#include "SerialPort.h"
#include "MotorSpeed.h"
#include "Calculation.h"

const int HALL_PIN = 2;
const int MOTOR_PIN = 3;
const int MOTOR_SPEED_PIN = A0;
const int MAX_DISTANCE = 8190;
const float RADIUS_CIRCLE = 32;

volatile float hallDiffTime;
volatile unsigned long hallLastTime;

DistanceSensor *distanceSensor = new RangingSensor();
HallSensor *hallSensor = new HallSensor();
SerialPort *serialPort = new SerialPort();
MotorSpeed *motorSpeed = new MotorSpeed();
Calculation *calc = new Calculation();

void setup()
{
  serialPort->begin(115200);
  distanceSensor->begin();
  hallSensor->begin(HALL_PIN, handleInterrupt, hallRotation);
  motorSpeed->begin(MOTOR_PIN, MOTOR_SPEED_PIN);
}

void loop()
{
  int distance = distanceSensor->readRangeInMillimeters();

  float angularSpeed = calc->angularSpeed(hallDiffTime);
  float linearSpeed = calc->linearSpeed(angularSpeed, RADIUS_CIRCLE);
  float angle = calc->angleInDegrees(angularSpeed, hallLastTime);
  
  motorSpeed->refresh();

  if (distance > MAX_DISTANCE)
  {
    return;
  }

  serialPort->send({angle, distance, MAX_DISTANCE, linearSpeed});
}

void hallRotation(float diffTime, unsigned long lastTime)
{
  hallDiffTime = diffTime;
  hallLastTime = lastTime;
}

void handleInterrupt()
{
  hallSensor->refresh();
}
