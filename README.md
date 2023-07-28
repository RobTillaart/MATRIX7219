
[![Arduino CI](https://github.com/RobTillaart/MATRIX7219/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/MATRIX7219/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/MATRIX7219/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/MATRIX7219/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/MATRIX7219/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/MATRIX7219/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/MATRIX7219.svg?maxAge=3600)](https://github.com/RobTillaart/MATRIX7219/releases)


# MATRIX7219

Arduino Library for 8x8 LED MATRIX MAX7219.


## Description

This library provides an easy access to 8x8 MATRIX boards.

- no buffering
- 


#### related




#### Tested

Tested on Arduino UNO.


## Interface

**\#include "MATRIX7219.h"**

Not all functionality works, matrix parameter et al.

- **MATRIX7219(uint8_t dataPin, uint8_t selectPin, uint8_t clockPin, uint8_t matrices)** 
Constructor, initializes IO pins and the number of 8x8 matrices on same pins.
- **void begin()** resets the internals of the connected device.
- **uint8_t  getMatrixCount()** returns number of matrices set in constructor.
Convenience function.
- **void setBrightness(uint8_t bn, uint8_t matrix)** bn = 0..15
- **void clear(uint8_t matrix)** clear the matrix.
- **void setRow(uint8_t row, uint8_t value, uint8_t matrix)** set a value to a certain row.


#### Reverse

Some 8x8 boards have their LEDS in other orientation. 
**setReverse(true)** might help to correct layout.

- **void     setReverse(bool rev)** reverse the output. Default = false.
- **bool     getReverse()** get current setting.


## Performance 

Preliminary tests

|  version  |  function     |  time (us)  |  notes  |
|:---------:|:-------------:|:-----------:|:--------|
|   0.1.0   | begin         |    796      |
|   0.1.0   | clear         |    1572     |
|   0.1.0   | count         |    4        |
|   0.1.0   | setRow(255)   |    204      | setReverse has minimal influence
|   0.1.0   | setRow(0)     |    200      |
|   0.1.0   | setBrightness |    208      |


## Future

#### Must

- improve documentation

#### Should

- test other platforms
- performance testing
  - increase.
- add unit tests
- create a derived class with a buffer
  - goal is to have **setPixel(x,y)** and **clearPixel(x,y)**

#### Could

- examples
  - 8x8 as debugger (dump variables)
  - clock ? binary - other?


#### Wont

