/*
 * global.h
 *
 *  Created on: Dec 1, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"
#include "controlLED.h"
#include "mode.h"
#include "input_processing.h"
#include "control7SEG.h"

#define TIMER_CYCLE		10

#define MODE_0_7SEG		111
#define MODE_1_7SEG		112
#define VALUE_0_7SEG	222
#define VALUE_1_7SEG	223

#define YELLOW_TIME		2
#define GREEN_TIME		3
#define RED_TIME		5

#define INIT 			0
#define MODE1			1
#define MODE2 			2
#define MODE3	 		3
#define MODE4			4

#define NUM_OF_MODES	4

extern int redTime;
extern int yellowTime;
extern int greenTime;
extern int ModeofLED;
extern int ValueofLED;

extern int mode;
extern int state;

void initValues();

#endif /* INC_GLOBAL_H_ */
