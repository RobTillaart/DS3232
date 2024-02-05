
[![Arduino CI](https://github.com/RobTillaart/DS3232/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/DS3232/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/DS3232/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/DS3232/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/DS3232/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/DS3232.svg)](https://github.com/RobTillaart/DS3232/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/DS3232/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/DS3232.svg?maxAge=3600)](https://github.com/RobTillaart/DS3232/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/DS3232.svg)](https://registry.platformio.org/libraries/robtillaart/DS3232)


# DS3232

Arduino library for I2C DS3232 real time clock and compatibles.


## Description

This DS3232 library provides a minimalistic interface to read from 
and write to the I2C DS3232 RTC device and compatibles.

What is different from other RTC libraries is that it directly provides fields like
seconds, minutes etc. and not use structs from libraries like time.h or timelib.h.
Goal is to improve the ease of use for those who just need date and time elements.

The library only supports the 24 hour / day model to minimize footprint.
Subtracting 12 is not too difficult if one wants an "AM/PM" layout.

The current version does not support any special feature other than a generic
**readRegister()** and **writeRegister()** function.
These two functions allows users access to all registers and to do anything possible.

For people who need a full function DS3232 library check the excellent library 
at https://github.com/JChristensen/DS3232RTC


Note: This library is a refactored version of an old DS3232 library from 2011
which was never published.


#### Tests

Tested with UNO.


#### Compatibles

DS3231 is compatible for time keeping part.
It does not have the SRAM the DS3232 has


#### Related

- https://github.com/JChristensen/DS3232RTC  (full featured DS3232 lib)
- https://github.com/RobTillaart/dateTimeHelpers


## Hardware

Always check datasheet for connections.

Pull ups are needed on SDA, SCL and other pins (datasheet).


## I2C 

#### Performance

I2C bus speeds officially supports up to 400 KHz.

timing on UNO of **read()** in microseconds

|  board   |  speed   |  time  |  notes  |
|:--------:|:--------:|:------:|:-------:|
|   UNO    |   50000  |  2011  |
|   UNO    |  100000  |  1072  |
|   UNO    |  200000  |   608  |
|   UNO    |  300000  |   442  |
|   UNO    |  400000  |   374  |  max official supported 
|   UNO    |  500000  |   328  |  indicative
|   UNO    |  600000  |   296  |  indicative
|   UNO    |  700000  |   280  |  indicative
|   UNO    |  800000  |   272  |  indicative


#### Address

Fixed address 0x68, see datasheet

#### I2C multiplexing

Imagine you want multiple clocks e.g. for different time zones, or
just to average them to be more precise.

Sometimes you need to control more devices than possible with the default
address range the device provides.
This is possible with an I2C multiplexer e.g. TCA9548 which creates up 
to eight channels (think of it as I2C subnets) which can use the complete 
address range of the device. 

Drawback of using a multiplexer is that it takes more administration in 
your code e.g. which device is on which channel. 
This will slow down the access, which must be taken into account when
deciding which devices are on which channel.
Also note that switching between channels will slow down other devices 
too if they are behind the multiplexer.

- https://github.com/RobTillaart/TCA9548


## Interface

```cpp
#include "DS3232.h"
```

#### Constructor

- **DS3232(const uint8_t address = DS3232_DEFAULT_ADDRESS, TwoWire \*wire = &Wire)** Constructor 
with default address (0x40) and I2C bus.
- **int begin()** initializes internals.
Returns error status.
- **bool isConnected()** checks if address (default 0x40) can be seen on the I2C bus.
- **uint8_t getAddress()** returns address set in constructor.


#### Base RTC

- **int read()** read the current time from the RTC.
- **int write()** set the current time in the RTC.
- **uint32_t lastRead()** lastTime in milliseconds when RTC is read.

#### Getters

Getters return cached value, to update call **read()** first.

- **uint8_t seconds()**
- **uint8_t minutes()**
- **uint8_t hours()**
- **uint8_t weekDay()**
- **uint8_t day()**
- **uint8_t month()**
- **uint8_t year()**

#### Setters

Setters set a cached value, to update the RTC call **write()** after.

- **void setSeconds(uint8_t value)**
- **void setMinutes(uint8_t value)**
- **void setHours(uint8_t value)**
- **void setDay(uint8_t value)**
- **void setMonth(uint8_t value)**
- **void setYear(uint8_t value)**

Note: weekDay cannot be set.


## Future

#### Must

- improve documentation.

#### Should

- test platforms
- test performance / footprint

#### Could

- split read() in readDate() + readTime()
  - date is not read so often?
- int getTemperature();
- SRAM 236 bytes
  - int SRAMwrite8(uint8_t index, uint8_t value);
  - int SRAMwrite16(uint8_t index, uint16_t value);
  - int SRAMwrite32(uint8_t index, uint32_t value);
  - int SRAMread8(uint8_t index, uint8_t value);
  - int SRAMread16(uint8_t index, uint16_t value);
  - int SRAMread32(uint8_t index, uint32_t value);
  - float and char array support?
- AM/PM support could be done in software.
  - simpler than decoding RTC?


#### Wont

Other extended functionality (or in derived class)


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


