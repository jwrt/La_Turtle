 /* Turtle Graphics Library for Turtle for LaFortuna
  ______           __  __        _____________  __
 /_  __/_  _______/ /_/ /__     / ____/ ____/ |/ /
  / / / / / / ___/ __/ / _ \   / / __/ /_   |   /
 / / / /_/ / /  / /_/ /  __/  / /_/ / __/  /   |
/_/  \__,_/_/   \__/_/\___/   \____/_/    /_/|_|

Implementation graphics methods for Turtle methods, built on:
  - Steve Gunn’s display driver
  - with functions heavily based on Adafruit's open source main GFX library
*/
/*
COPYRIGHT DECLARATION
Copyright (c) 2013 Adafruit Industries.  All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#include "lcd.h"
#include <stdlib.h>

//Helper Function
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }

void writePixel(uint16_t x, uint16_t y, uint16_t col);

void fastHLineRight(uint16_t x, uint16_t y,uint16_t l, uint16_t col);
void fastHLineLeft(uint16_t x, uint16_t y,uint16_t l, uint16_t col);

void fastVLineDown(uint16_t x, uint16_t y,uint16_t h, uint16_t col);
void fastVLineUp(uint16_t x, uint16_t y,uint16_t h, uint16_t col);

void drawFastVLine(int16_t x, int16_t y,int16_t h, uint16_t color);
void drawFastHLine(int16_t x, int16_t y,int16_t w, uint16_t color);

void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawCircle(int16_t x0, int16_t y0, int16_t r,uint16_t color);

void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void fillCircle(int16_t x0, int16_t y0, int16_t r,uint16_t color);
