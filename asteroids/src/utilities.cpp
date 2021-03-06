#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/** Utilities used by the other functions **/

int randrange(int from, int to){
	int range = to-from;
	return rand()%range + from;
}
float radians(float a){
	const float pi = 3.141592;
	return a * pi /180.0f;
}
