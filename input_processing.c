/*
 * input_processing.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ASUS
 */


#include "input_processing.h"

int seg_counter;
int tempVal;

void fsm_input_processing() {
	//traffic system works as 4 modes
	switch (mode) {
	//Init mode, in here we preset all values then change to MODE1
	case INIT:
		seg_counter = 2;
		segRun1();
		setTimer2(500);
		mode = MODE1;
		break;
	case MODE1:
		//In MODE1, we have 2 traffic systems to control
		mode1Run();
		if (timer2_flag == 1) {
			setTimer2(500);
			if (seg_counter == 2) {
				segRun2();
				ValueofLED--;
				ModeofLED--;
				seg_counter = 0;
			} else {
				segRun1();
			}
			seg_counter++;
		}
		//if we press button 1, system will change to MODE2
		if (isButtonPressed(BUTTON_1_PRESS) == 1) {
			setTimer2(500);
			tempVal = redTime;
			ModeofLED = MODE2;
			ValueofLED = redTime;
			mode = MODE2;
			offAllLeds();
		}
		break;
	case MODE2:
		//In MODE2, we use button 2 and 3 to adjust duration of red light
		if (timer2_flag == 1) {
			setTimer2(500);
			blinkingLeds();
			if (seg_counter == 2) {
				segRun2();
				seg_counter = 0;
			} else {
				segRun1();
			}
			seg_counter++;
		}
		//if we press button 1, system will change to MODE3
		if (isButtonPressed(BUTTON_1_PRESS) == 1) {
			setTimer2(500);
			tempVal = yellowTime;
			ModeofLED = MODE3;
			ValueofLED = yellowTime;
			mode = MODE3;
			offAllLeds();
		}
		//if we press button 2, duration of red light will increase 1s
		if (isButtonPressed(BUTTON_2_PRESS) == 1) {
			if (tempVal > 99) {
				tempVal = 1;
			}
			tempVal++;
			ValueofLED = tempVal;
		}
		//if we press button 3, system will save the change to red light
		if (isButtonPressed(BUTTON_3_PRESS) == 1) {
			redTime = tempVal;
			ValueofLED = redTime;
		}
		break;
		//MODE3 is similar to MODE2
	case MODE3:
		if (timer2_flag == 1) {
			setTimer2(500);
			blinkingLeds();
			if (seg_counter == 2) {
				segRun2();
				seg_counter = 0;
			} else {
				segRun1();
			}
			seg_counter++;
		}
		if (isButtonPressed(BUTTON_1_PRESS) == 1) {
			setTimer2(500);
			tempVal = greenTime;
			ModeofLED = MODE4;
			ValueofLED = greenTime;
			mode = MODE4;
			offAllLeds();
		}
		if (isButtonPressed(BUTTON_2_PRESS) == 1) {
			if (tempVal > 99) {
				tempVal = 1;
			}
			tempVal++;
			ValueofLED = tempVal;
		}
		if (isButtonPressed(BUTTON_3_PRESS) == 1) {
			yellowTime = tempVal;
			ValueofLED = yellowTime;
		}
		break;
		//MODE4 is similar to MODE1
	case MODE4:
		if (timer2_flag == 1) {
			setTimer2(500);
			blinkingLeds();
			if (seg_counter == 2) {
				segRun2();
				seg_counter = 0;
			} else {
				segRun1();
			}
			seg_counter++;
		}
		if (isButtonPressed(BUTTON_1_PRESS) == 1) {
			state = init;
			seg_counter = 2;
			segRun1();
			setTimer2(500);
			mode = MODE1;
		}
		if (isButtonPressed(BUTTON_2_PRESS) == 1) {
			if (tempVal > 99) {
				tempVal = 1;
			}
			tempVal++;
			ValueofLED = tempVal;
		}
		if (isButtonPressed(BUTTON_3_PRESS) == 1) {
			greenTime = tempVal;
			ValueofLED = greenTime;
		}
		break;
	default:
		break;
	}
}

