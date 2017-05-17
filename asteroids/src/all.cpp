/** ASTEROIDS **/

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <display.h>
#include <mbed.h>
#include <utilities.h>
#include <controls.h>
#include <physics.h>
#include <drawing.h>

Ticker drawing;
Ticker model;
Ticker controller;
Ticker asteroids;
static const float Dt = 0.01;
static const float drawTick = 0.025;
static const float controlTick = 0.1;
static const float asteroidTick = 0.1;

#define initLive 5

/** Main Function with initialisation **/

int main(){
    initialise_heap();
    initialise_asteroidheap();
    init_double_buffering();
		initialvalues();
		lives=initLive;
		drawing.attach(draw, drawTick);//timer to show and drawing on screen
		model.attach(physics, Dt);//timer for the physics
		controller.attach(controls, controlTick);//timer for controller
		asteroids.attach(asteroid_system, asteroidTick);//timer for asteroids to spawn
		while(1){
		if(lives==0){
			drawing.detach();
			gameovertext();
			model.detach();
			controller.detach();
			asteroids.detach();
			if(startagain()){
				initScreen();
				totalscore=0;
				totaltimealive=0;
				initialvalues();
				lives=initLive;
				drawing.attach(draw, 0.025);
				model.attach(physics, Dt);
				controller.attach(controls, 0.1);
				asteroids.attach(asteroid_system, 0.1);
			}
		}
	}
}
