/*______           __  __        _____________  __
 /_  __/_  _______/ /_/ /__     / ____/ ____/ |/ /
  / / / / / / ___/ __/ / _ \   / / __/ /_   |   /
 / / / /_/ / /  / /_/ /  __/  / /_/ / __/  /   |
/_/  \__,_/_/   \__/_/\___/   \____/_/    /_/|_|

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

#include "turtleGFX.h"
#include <util/delay.h>

void writePixel(uint16_t x, uint16_t y, uint16_t col){
	rectangle r = {x, x, y, y};
	fill_rectangle(r,col);
	//This could be used for a speed setting!
	//_delay_ms(5);
}

void fastHLineRight(uint16_t x, uint16_t y,uint16_t l, uint16_t col){

	rectangle r = {x, x+l, y, y};
	fill_rectangle(r,col);
}

void fastHLineLeft(uint16_t x, uint16_t y,uint16_t l, uint16_t col){

	rectangle r = {x-l, x, y, y};
	fill_rectangle(r,col);
}


void fastVLineDown(uint16_t x, uint16_t y,uint16_t h, uint16_t col){

	rectangle r = {x, x, y, y+h};
	fill_rectangle(r,col);
}

void fastVLineUp(uint16_t x, uint16_t y,uint16_t h, uint16_t col){

	rectangle r = {x, x, y-h, y};
	fill_rectangle(r,col);
}


void drawFastVLine(int16_t x, int16_t y,int16_t h, uint16_t color){
 fastVLineDown(x, y, h , color);
}
void drawFastHLine(int16_t x, int16_t y,int16_t w, uint16_t color){
	fastHLineRight(x,y,w,color);
}

// Bresenham's algorithm - thx wikpedia
void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        _swap_int16_t(x0, y0);
        _swap_int16_t(x1, y1);
    }

    if (x0 > x1) {
        _swap_int16_t(x0, x1);
        _swap_int16_t(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            writePixel(y0, x0, color);
        } else {
            writePixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

void drawCircle(int16_t x0, int16_t y0, int16_t r,
        uint16_t color) {
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    writePixel(x0  , y0+r, color);
    writePixel(x0  , y0-r, color);
    writePixel(x0+r, y0  , color);
    writePixel(x0-r, y0  , color);

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        writePixel(x0 + x, y0 + y, color);
        writePixel(x0 - x, y0 + y, color);
        writePixel(x0 + x, y0 - y, color);
        writePixel(x0 - x, y0 - y, color);
        writePixel(x0 + y, y0 + x, color);
        writePixel(x0 - y, y0 + x, color);
        writePixel(x0 + y, y0 - x, color);
        writePixel(x0 - y, y0 - x, color);
    }
}
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color){
	int16_t f     = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x     = 0;
    int16_t y     = r;

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f     += ddF_y;
        }
        x++;
        ddF_x += 2;
        f     += ddF_x;

        if (cornername & 0x1) {
            drawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
            drawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
        }
        if (cornername & 0x2) {
            drawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
            drawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
        }
    }
}

void fillCircle(int16_t x0, int16_t y0, int16_t r,uint16_t color) {
    drawFastVLine(x0, y0-r, 2*r+1, color);
    fillCircleHelper(x0, y0, r, 3, 0, color);
}
