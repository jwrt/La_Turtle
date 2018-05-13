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

#include "turtle.h"

float vertPos;
float horiPos;
uint16_t heading = 0;
uint16_t penCol = BLACK;
int penIsDown = 0;


//Moves Pen to a location
void goTo(float x, float y){
	if(penIsDown){
          writeLine(horiPos, vertPos, x, y, penCol);
	  vertPos = y;
          horiPos = x;
	}else{
	  vertPos = y;
          horiPos = x;
	}
}

void setpos(int16_t x, int16_t y){
 goTo(x,y);
}

void setx(int16_t x){
	if(penIsDown){
          writeLine(horiPos, vertPos, x, horiPos, penCol);
          horiPos = x;
	}else{
          horiPos = x;
	}
}

void sety(int16_t y){
	if(penIsDown){
          writeLine(horiPos, vertPos, horiPos, y, penCol);
	  vertPos = y;
	}else{
	  vertPos = y;
	}
}



void setposition(int16_t x, int16_t y){
 goTo(x,y);
}

void penup(){
  penIsDown = 0;
}

void up(){
  penup();
}

void pu(){
  penup();
}


void pendown(){
  penIsDown = 1;
}

void down(){
 pendown();
}

void pd(){
 pendown();
}

//Sets Heading (0==North, 90==East etc.)
void setHeading(int16_t h){
		if(h<0){
			h=360+h;
		}
			 heading =  h % 360 ;
			 //DEBUG
			 //char snum[5];
       //itoa(heading, snum, 10);
			 //display_string(snum);
			 //display_char(',');
}

void seth(int16_t h){
     setHeading(h);
}

void right(int16_t degs){
     seth(heading+degs);
}

void rt(int16_t degs){
	right(degs);
}

void left(int16_t degs){
     seth(heading-degs);
}

void lt(int16_t degs){
     left(degs);
}



void color(uint16_t col){
	penCol = col;
}

void randColor(){
	int16_t currRand = rand()%9;

	if(currRand<1){
    penCol = WHITE;
		return;
	}
	if(currRand<2){
		penCol = BLACK;
		return;
	}
	if(currRand<3){
    penCol = BLUE;
		return;
	}
	if(currRand<4){
    penCol = GREEN;
		return;
	}
	if(currRand<5){
    penCol = CYAN;
		return;
	}
	if(currRand<6){
    penCol = RED;
		return;
	}
	if(currRand<7){
    penCol = MAGENTA;
		return;
	}
	if(currRand<8){
    penCol = YELLOW;
		return;
	}

}

uint16_t getRandColor(){
	int16_t currRand = rand()%9;

	if(currRand<1){
		return WHITE;
	}
	if(currRand<2){
		return BLACK;
	}
	if(currRand<3){
		return BLUE;
	}
	if(currRand<4){
  	return GREEN;
	}
	if(currRand<5){
    return CYAN;
	}
	if(currRand<6){
    return RED;
	}
	if(currRand<7){
    return MAGENTA;
	}
	if(currRand<8){
    return YELLOW;
	}

}


//Returns Pen to center point
void home(){
   goTo(display.width/2,display.height/2);
}

//Draws circle of given radius, with center at current pen location
void circle(int16_t r){
	drawCircle(horiPos,vertPos,r,penCol);
}

//Draws a filled circle of given radius, with center at current pen location
void dot(int16_t r){
	fillCircle(horiPos,vertPos,r,penCol);
}

void forward(int16_t dist){
  //Add hori and vert pos update

  switch(heading) {
      case 0 :
         fastVLineUp(horiPos,vertPos,dist, penCol);
         vertPos = vertPos-dist;
         return;
      case  180 :
         fastVLineDown(horiPos,vertPos,dist, penCol);
         vertPos = vertPos+dist;
         return;
      case 90 :
         fastHLineRight(horiPos,vertPos,dist, penCol);
         horiPos = horiPos+dist;
         return;
      case 270:
         fastHLineLeft(horiPos,vertPos,dist, penCol);
         horiPos = horiPos-dist;
         return;
 }

   if(heading>0 && heading<90){
     float newHori = horiPos + (dist*(cos(degToRad(90-heading))));
     float newVert = vertPos - (dist*(sin(degToRad(90-heading))));
     goTo(newHori, newVert);
     return;
   }
   if(heading>90 && heading<180){
     float newHori = horiPos + (dist*(cos(degToRad(heading-90))));
     float newVert = vertPos + (dist*(sin(degToRad(heading-90))));
     goTo(newHori, newVert);
     return;
   }
   if(heading>180 && heading<270){
     float newHori = horiPos - (dist*(sin(degToRad(heading-180))));
     float newVert = vertPos + (dist*(cos(degToRad(heading-180))));
     goTo(newHori, newVert);
     return;
   }
   if(heading>270 && heading<360){
     float newHori = horiPos - (dist*(cos(degToRad(heading-270))));
     float newVert = vertPos - (dist*(sin(degToRad(heading-270))));
     goTo(newHori, newVert);
     return;
   }
}

void fd(int16_t dist){
     forward(dist);
}

void clear(){
	clear_screen();
}

void reset(){
	penup();
	seth(0);
	home();
	pendown();
}
