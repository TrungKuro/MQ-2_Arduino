/*!
 *  @file MQ2.cpp
 *
 *  Library Sensor MQ2 use with boards Arduino
 *  Function tests levels of gas in the air
 *
 *  @section author Author
 *
 *  Written by TrungKuro
 *
 *  @section license License
 *
 *  Hshop license, all text above must be included in any redistribution
 */

#include "MQ2.h"

/*!
 *  @brief  Instantiates a new MQ2 class
 *  @param  pin
 *          Pin number that sensor is connected (note: use pin Analog)
 *  @param  isPower5v
 *          The sensor use logic 3.3v or 5v (default 5v)
 *  @param  res2
 *          The value Resistance R2 of sensor (default 2KOhm)
 */
MQ2::MQ2(uint8_t pin, bool isPower5v, float res2)
{
  _pin = pin;
  _isPower5v = isPower5v;
  _res2 = res2;
}

/////////////////////////////////////////////////////////////////////

/*!
 *  @brief  It will delay ~20s to heat probe sensor to ready
 *          Then calculate value RO based on RS
 */
void MQ2::begin()
{
  delay(19000);
  _resO=0;

  uint8_t count=10;
  uint8_t i=count;
  while (i--)
  {
    _resO += (MQ2::calculateRS()/AIR); // Calculate the average of RO (RO = RS/9.6)
    delay(100);
  }
  _resO /= (float)count;
}

/*!
 *  @brief  Calculate the concentration of gas is present in Air, unit (ppm)
 */
float MQ2::readGasConcentration()
{
  return 600 * pow(MQ2::calculateRS()/_resO, -2.07);
}

/////////////////////////////////////////////////////////////////////

/*!
 *  @brief  Calculate value RS based on R2 and level Logic with the value Analog voltage of sensor
 */
float MQ2::calculateRS()
{
  float sensorValue = analogRead(_pin);
  float sensorVolt = sensorValue * (_isPower5v?5.0:3.3) / (_isPower5v?1024.0:675.84);
  float RS = (_isPower5v?5.0:3.3) * _res2 / sensorVolt - _res2;

  return RS;
}
