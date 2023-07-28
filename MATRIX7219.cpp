//
//    FILE: MATRIX7219.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2023-07-28
// PURPOSE: Arduino Library for 8x8 LED MATRIX MAX7219
//     URL: https://github.com/RobTillaart/MATRIX7219


#include "MATRIX7219.h"

#define MATRIX7219_DECODE_MODE     0x09
#define MATRIX7219_BRIGHTNESS      0x0A
#define MATRIX7219_SCAN_LIMIT      0x0B
#define MATRIX7219_SHUT_DOWN       0x0C
#define MATRIX7219_DISPLAY_TEST    0x0F


MATRIX7219::MATRIX7219(uint8_t dataPin, uint8_t selectPin, uint8_t clockPin, uint8_t matrices)
{
  _dataPin   = dataPin;
  _selectPin = selectPin;
  _clockPin  = clockPin;
  _matrices  = matrices;

   pinMode(_dataPin,  OUTPUT);
   pinMode(_selectPin,OUTPUT);
   pinMode(_clockPin, OUTPUT);

   digitalWrite(_dataPin,  HIGH);
   digitalWrite(_selectPin,HIGH);
   digitalWrite(_clockPin, HIGH);
}


uint8_t MATRIX7219::getMatrixCount()
{
  return _matrices;
}


void MATRIX7219::begin()
{
  for (int m = 0; m < _matrices; m++)
  {
    digitalWrite(_selectPin, LOW);
    _write(MATRIX7219_SCAN_LIMIT);
    _write(0x07);
    digitalWrite(_selectPin, HIGH);
  }
  for (int m = 0; m < _matrices; m++)
  {
    digitalWrite(_selectPin, LOW);
    _write(MATRIX7219_DECODE_MODE);
    _write(0x00);                       //  No decode for digits 7–0
    digitalWrite(_selectPin, HIGH);
  }
  for (int m = 0; m < _matrices; m++)
  {
    digitalWrite(_selectPin, LOW);
    _write(MATRIX7219_SHUT_DOWN);
    _write(0x01);
    digitalWrite(_selectPin, HIGH);
  }
  for (int m = 0; m < _matrices; m++)
  {
    digitalWrite(_selectPin, LOW);
    _write(MATRIX7219_DISPLAY_TEST);
    _write(0x00);                       //  normal mode
    digitalWrite(_selectPin, HIGH);
  }
}


void MATRIX7219::setBrightness(uint8_t bn)
{
  if (bn > 15) bn = 15;

  digitalWrite(_selectPin, LOW);
  for (int m = 0; m < _matrices; m++)
  {
    _write(MATRIX7219_BRIGHTNESS);
    _write(bn);
  }
  digitalWrite(_selectPin, HIGH);
}


void MATRIX7219::clear()
{
  for (uint8_t row = 1; row < 9; row++)
  {
    digitalWrite(_selectPin, LOW);
    for (int m = 0; m < _matrices; m++)
    {
      _write(row);
      _write(0);
    }
    digitalWrite(_selectPin, HIGH);
  }
}


void MATRIX7219::setRow(uint8_t row, uint8_t value, uint8_t matrix)
{
  digitalWrite(_selectPin, LOW);
  for (int m = _matrices; m > matrix; m--)
  {
    _write(0);
    _write(0);
  }
  
  _write(row);
  if (_reverse) _write(255 - value);
  else          _write(value);
  
  for (int m = matrix-1; m > 0; m--)
  {
    _write(0);
    _write(0);
  }
  digitalWrite(_selectPin, HIGH);
}


void MATRIX7219::setReverse(bool rev)
{
  _reverse = rev;
}


bool MATRIX7219::getReverse()
{
  return _reverse;
}


///////////////////////////////////////////////////////
//
//  PRIVATE
//
void MATRIX7219::_write(uint8_t b)
{
  for (uint8_t mask = 0x80; mask > 0; mask >>= 1) 
  {
    digitalWrite(_clockPin, LOW);
    digitalWrite(_dataPin, (b & mask) > 0);
    digitalWrite(_clockPin, HIGH);
  }
}

//  optimization not for release 0.1.0
void MATRIX7219::_writeZero()
{
  digitalWrite(_dataPin, LOW);
  for (uint8_t mask = 0x80; mask > 0; mask >>= 1) 
  {
    digitalWrite(_clockPin, LOW);
    digitalWrite(_clockPin, HIGH);
  }
}


//  -- END OF FILE --

