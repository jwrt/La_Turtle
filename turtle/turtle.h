 /* Turtle Graphics for LaFortuna
  ______           __  __
 /_  __/_  _______/ /_/ /__
  / / / / / / ___/ __/ / _ \
 / / / /_/ / /  / /_/ /  __/
/_/  \__,_/_/   \__/_/\___/

Implementation of Logos Turtle Graphics, built on:
  - Steve Gunn’s display driver
  - with functions heavily based on Adafruit's open source main GFX library
  - packaged with FortunaOS with RIOS scheduler and Ruota switch reader
Method signatures on the whole match with Logos (and Python) for compatibility

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

#include "os.h"
#include "turtleGFX.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Helper Function
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

//MOVE and DRAW
void forward(int16_t dist);
void fd(int16_t dist);

void right(int16_t degs);
void rt(int16_t degs);

void left(int16_t degs);
void lt(int16_t degs);

//Note Camel-case to avoid reserved keyword conflict
void goTo(float x, float y);
void setpos(int16_t x, int16_t y);
void setposition(int16_t x, int16_t y);
void setx(int16_t x);
void sety(int16_t y);

//Set new Heading (in Degrees)
void setHeading(int16_t h);
void seth(int16_t h);
void home();
void reset();
void circle(int16_t r);
void dot(int16_t r);

//PEN CONTROL
void pendown();
void pd();
void down();

void penup();
void pu();
void up();

//COLOR
void color(uint16_t col);
void randColor();

//get a randomColor
uint16_t getRandColor();

//clears display
void clear();

//FUTURE WORK
//speed();
//position() | pos()
//towards()
//xcor()
//ycor()
//heading()
//distance()
//pensize() | width()
//pen()
//isdown()
// Drawing a certain extent of a circle for arcs
