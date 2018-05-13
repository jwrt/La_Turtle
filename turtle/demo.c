/*______           __  __
 /_  __/_  _______/ /_/ /__
  / / / / / / ___/ __/ / _ \
 / / / /_/ / /  / /_/ /  __/
/_/  \__,_/_/   \__/_/\___/
*/
#include "demo.h"

void concentricCircles(uint16_t col,int16_t spacing,int16_t centrePosX, int16_t centrePosY){
  penup();
  setpos(centrePosX,centrePosY);
  pendown();
  color(col);
  int16_t a = 10;
  while(a < 200){
    circle(a);
    a = a+spacing;
  }
}

void concentricCirclesRand(int16_t quantity){
   int16_t i = 0;
   while(i<quantity){
     int16_t currRand = rand();
     int16_t spacing = ((currRand%40) >= (5)) ? (currRand%40) : (5);
     concentricCircles(getRandColor(), spacing, currRand%LCDWIDTH,currRand%LCDHEIGHT);
     i++;
   }
 }

void concentricCirclesRainbow(int16_t spacing,int16_t centrePosX, int16_t centrePosY){
  penup();
  setpos(centrePosX,centrePosY);
  pendown();
  int16_t a = 10;
  while(a < 200){
    randColor();
    circle(a);
    a = a+spacing;
  }
}

void squareSpiral(uint16_t col){
  color(col);
  int side=10;
  reset();

  int i = 1;
  while(i<=100){
   fd(side);
   right(92);
   side = side+5;
   i = i +1;
 }
}

void spotsRainbowRand(int16_t quantity){
  int16_t i = 0;
  while(i<quantity){
    int16_t currRand = rand();
    penup();
    int16_t dotSize= ((currRand%100) >= (5)) ? (currRand%100) : (5);
    setpos(currRand%LCDWIDTH,(currRand%(LCDHEIGHT-dotSize))+dotSize);
    pendown();
    randColor();

    dot(dotSize);
    i++;
  }
}

void star(){
  reset();
  seth(90);
  int16_t i = 0;
  while(i<50){
    fd(50);
    rt(144);
    i++;
  }
}

void drawSquare(){
  reset();
  forward(50);
  rt(72);
  forward(50);
  rt(72);
  forward(50);
  rt(72);
  forward(50);
  rt(72);
  forward(50);

}

void triangleRing(){
  penup();
  home();
  seth(0);
  fd(30);
  pendown();
  randColor();

  int16_t i = 0;
while(i<12){
  rt(90);
  fd(60);
  lt(120);
  fd(60);
  lt(120);
  fd(60);
  fd(60);
  i++;
}

}

void snowFlake(int16_t length, int16_t depth){
  if( depth == 0){
     forward(length);
   }else{
     snowFlake(length/3, depth-1);
     right(60);
     snowFlake(length/3, depth-1);
     left(120);
     snowFlake(length/3, depth-1);
     right(60);
     snowFlake(length/3, depth-1);
   }
}
