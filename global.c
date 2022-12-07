/*
 * global.c
 *
 *  Created on: Dec 1, 2022
 *      Author: ASUS
 */

#include "global.h"

int mode = INIT;
int status = 0;
int state = init;

int yellowTime;
int greenTime;
int redTime;

int ModeofLED;
int ValueofLED;

void initValues() {
	yellowTime = YELLOW_TIME;
	greenTime = GREEN_TIME;
	redTime = RED_TIME;
	ModeofLED = redTime;
	ValueofLED = greenTime;
}
