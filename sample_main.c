#include "demo.h"

int update_dial(int);
int collect_delta(int);
int check_switches(int);

//DEMO program to show how the turtle library can be used
void main(void) {
    //Initialises FortunaOS, which initialises the clock, led, lcd, scheduler, rotary encoder, uart
    os_init();

    //Move pen to start at center point
    home();

    //Aim North to start
    setHeading(0);

    //Init Background
    display.background = GRAY;
    clear_screen();

    //Welcome Screen
    display_string_xy("LaTurtle Graphics",15,50);
    snowFlake(1000,6);
    display_string_xy("DEMO",15,100);
    display_string_xy("Try any Key!",15,150);

    //Adds tasks to RIOS scheduler. (function pointer, period(ms), start state)
    os_add_task( check_switches,  10, 1);

    //Enable global interrupts
    sei();

    //Empty infinite main program loop
    for(;;){}
}

//Uses ruota.c to read current states of all switches
int check_switches(int state) {

  //NORTH BUTTON (short press)
	if (get_switch_press(_BV(SWN))) {
	    clear();
      triangleRing();
	}

//EAST BUTTON (short press)
	if (get_switch_press(_BV(SWE))) {
		clear();
    spotsRainbowRand(10);
	}

  //SOUTH BUTTON (short press)
	if (get_switch_press(_BV(SWS))) {
      clear();
      concentricCirclesRainbow(5,display.width/2,display.height/2);
	}

  //WEST BUTTON (short press)
	if (get_switch_press(_BV(SWW))) {
		  clear();
      squareSpiral(getRandColor());
	}

  //CENTER BUTTON (short press)
	if (get_switch_short(_BV(SWC))) {
      clear();
      concentricCirclesRand(5);
	}
	return state;
}
