//
//    FILE: MATRIX7219_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo of MATRIX7219 8x8 LED MATRIX MAX7219
//     URL: https://github.com/RobTillaart/MATRIX7219


#include "MATRIX7219.h"

uint8_t data   = 2;
uint8_t select = 3;
uint8_t clock  = 4;
uint8_t count  = 1;

MATRIX7219 mx(data, select, clock, count);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("MATRIX7219_LIB_VERSION: ");
  Serial.println(MATRIX7219_LIB_VERSION);

  mx.begin();
  mx.clear(1);
  delay(1000);

  Serial.println(mx.getMatrixCount());

  for (int n = 1; n < 9; n++)
  {
    mx.setRow(n, random(255), 1);
  }
  for (int n = 1; n < 7; n++)
  {
    mx.setBrightness(n, 0);
    delay(100);
  }
  mx.setBrightness(3, 0);
  delay(100);
}


void loop()
{
  for (int n = 1; n < 9; n++)
  {
    mx.setRow(n, random(255), 1);
    delay(1000);
  }
}


//  -- END OF FILE --