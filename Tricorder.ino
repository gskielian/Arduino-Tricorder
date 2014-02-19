// Draw Boxes - Demonstrate drawRectangle and fillRectangle
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <Wire.h>
#include "Adafruit_TMP006.h"
#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>

Adafruit_TMP006 tmp006;

#ifdef SEEEDUINO
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 14   // can be a digital pin, this is A0
  #define XP 17   // can be a digital pin, this is A3 
#endif

#ifdef MEGA
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 54   // can be a digital pin, this is A0
  #define XP 57   // can be a digital pin, this is A3 
#endif 

void setup()
{
  if (! tmp006.begin()) {
    Serial.println("No sensor found");
    while (1);
  }
Tft.init();  //init TFT library

/*  Demo of 
    drawRectangle(unsigned int poX, unsigned int poY, unsigned int length,unsigned int width,unsigned int color);
    fillRectangle(unsigned int poX, unsigned int poY, unsigned int length, unsigned int width, unsigned int color);
*/
 Tft.drawRectangle(10, 3, 200,60,BLUE);
 Tft.drawString("Monitor",15,6,4,WHITE);

 Tft.drawRectangle(30, 160, 60, 60,RED);
 float objt = tmp006.readObjTempC();   delay(4000); // 4 seconds per reading for 16 samples per reading
 String myString = String(objt);
 char charBuf[4];
 myString.toCharArray(charBuf,4);
   Tft.drawString(charBuf,35,165,2,CYAN);
   }

void loop()
{delay(4000);
   Tft.fillRectangle(30, 160, 60, 60,BLACK);
 float objt = tmp006.readObjTempC();    // 4 seconds per reading for 16 samples per reading
 String myString = String(objt);
 char charBuf[4];
 myString.toCharArray(charBuf,4);
   Tft.drawString(charBuf,35,165,2,CYAN);
}
