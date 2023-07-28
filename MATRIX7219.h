#pragma once
//
//    FILE: MATRIX7219.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2023-07-28
// PURPOSE: Arduino Library for 8x8 LED MATRIX MAX7219
//     URL: https://github.com/RobTillaart/MATRIX7219


#include "Arduino.h"


#define MATRIX7219_LIB_VERSION        (F("0.1.0"))


class MATRIX7219
{
public:
  MATRIX7219(uint8_t dataPin, uint8_t selectPin, uint8_t clockPin, uint8_t matrices = 1);

  uint8_t  getMatrixCount();
  void     begin();


  //  bn = 0..15
  void     setBrightness(uint8_t bn, uint8_t matrix);
  void     clear(uint8_t matrix);

  //  row   = 1..8
  //  value = 0..255
  void     setRow(uint8_t row, uint8_t value, uint8_t matrix);

  void     setReverse(bool rev);
  bool     getReverse();

private:

  void     _write(uint8_t b);
  void     _writeZero();         //  optimized  writing of all 0

  uint8_t  _dataPin;
  uint8_t  _selectPin;
  uint8_t  _clockPin;
  uint8_t  _matrices;

  bool     _reverse = false;
};



//  -- END OF FILE -- 

