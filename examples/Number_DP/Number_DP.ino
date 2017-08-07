/*
 Project 10: Serial 7-Segment LED Display

 This program will display running numbers on Serial 7-Segment LED Display

*/

#include "TM1637.h"

#define CLK 2   // CLK pin on the Serial 7-Segment LED Display connects to digital pin 2.
#define DIO 3   // DIO on the Serial 7-Segment LED Display connects to digital pin 3.

//Value to display on 7-Segment LED
//0~9,A,b,C,d,E,F
int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //0~9,A,b,C,d,E,F
int8_t posDisp[4];
unsigned char i = 0;
unsigned char count = 0;

// Initialize the TM1637 library, telling it which digital pins will be used
// to interface to the Serial 7-Segment LED Display
TM1637 tm1637(CLK, DIO);

void setup()
{
  tm1637.init();

  //Set the brightness of LED
  //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7
  tm1637.set(BRIGHT_TYPICAL);
}

void loop()
{
  i = count;
  count ++;
  if (count == sizeof(NumTab))
    count = 0;
  for (unsigned char BitSelect = 0; BitSelect < 4; BitSelect ++)
  {
    posDisp[BitSelect] = NumTab[i];
    i ++;
    if (i == sizeof(NumTab))
      i = 0;
  }
  tm1637.display(0, posDisp[0], POINT_ON); //display first digit, Decimal Point (DP) on
  tm1637.display(1, posDisp[1], POINT_OFF); //dispaly 2nd digit, DP off
  tm1637.display(2, posDisp[2], POINT_OFF); //display 3rd digit, DP off
  tm1637.display(3, posDisp[3], POINT_OFF); //display 4th digit, DP off
  delay(500); //short delay
}
