#include <MQ2.h>

#define MQ_PIN A0

MQ2 mq(MQ_PIN, false, 1000); // Here I use sensor have logic 3.3v (isPower5v=false) and R2=1kOhm (default 2kOhm)

void setup()
{
  Serial.begin(9600);
  Serial.print(F("MQ2 test!\n"));
  Serial.print(F("Please wait for the sensor probe to warm up (~20s)\nThe program is calculating the value of RO..."));
  mq.begin();
  Serial.print(F("ready\n"));
}

void loop()
{
  float gas = mq.readGasConcentration(); // Unit (ppm)

  Serial.print(F("Level Gas: "));
  Serial.print(gas, 0); Serial.print(F(" ppm\n"));
  
  delay(1000);
}
