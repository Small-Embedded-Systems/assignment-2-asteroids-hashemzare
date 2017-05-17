#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <display.h>
#include <mbed.h>
#include <physics.h>
#include <controls.h>

/** Joystick pozition inputs **/

enum position { JLEFT,JDOWN,JRIGHT,JUP,JCENTRE};
DigitalIn buttons[] = {P5_0, P5_1, P5_4, P5_2, P5_3};

/** Joystick controls **/

#define turnPoint 9
#define accMax 2
#define accInc 0.2

void controls(void){
  if(ispressed(JLEFT)){
    headingAngle=headingAngle+turnPoint;
  } else if(ispressed(JRIGHT)){
    headingAngle=headingAngle-turnPoint;
  } else if(ispressed(JUP)){
		if(accel<accMax){//ship travels at max speed 2
			accel=accel+accInc;
		}
  }
	if(ispressed(JCENTRE)){
		missile_system();
  }
}

bool startagain(void){
	if(lives==0 && ispressed(JCENTRE)){
		return true;
	}
	return false;
}

bool ispressed(enum position p){
    return !buttons[p];
}
