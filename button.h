
#include "main.h"


#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define BUTTON_1_PRESS				0
#define BUTTON_2_PRESS				1
#define	BUTTON_3_PRESS				2
#define NORMAL_STATE 				SET
#define PRESSED_STATE 				RESET
#define NUM_OF_BUTTONS				3
#define TIME_OUT_FOR_KEY_PRESS		100

extern int button_flag[NUM_OF_BUTTONS];
void getKeyInput();
void subKeyProcess(int index);
int isButtonPressed(int index);
#endif /* INC_BUTTON_H_ */
