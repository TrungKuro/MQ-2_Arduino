# MQ2 Gas Sensor Library
Library sensor MQ-2 for **boards Arduino**
<p align="center"><img src="/assets/mq-2.jpg"/></p>

## Constructors
```
MQ2(uint8_t pin, bool isPower5v=true, float res2=2000);
```
+ pin      : the pin Analog connect
+ isPower5v: the level logic of sensor (default 5v)
+ res2     : the resistor R2 base on Schematic (default 2kΩ)

## Methods

### Need calculate RO before used, wait ~20s
```
void begin();
```

### Get value, unit (ppm)
```
float readGasConcentration();
```
