/*!
 *  @file MQ2.h
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

#ifndef MQ2_H
#define MQ2_H

#include <Arduino.h>

#define AIR 9.6 // The RS/R0 ratio is a constant 9.6 in "clean air"

class MQ2
{
public:
  MQ2(uint8_t pin, bool isPower5v=true, float res2=2000);

  void begin();
  float readGasConcentration(); // Unit (ppm), based on ratio RS/RO

private:
  uint8_t _pin;
  float _res2, _resO;
  bool _isPower5v;

  float calculateRS();
};

#endif
