/*
 * control7SEG.h
 *
 *  Created on: Dec 1, 2022
 *      Author: ASUS
 */

#ifndef INC_CONTROL7SEG_H_
#define INC_CONTROL7SEG_H_


#include "global.h"

void segRun1();
void segRun2();
void display7SEG(int counter);
void update7SEG_Mode(int index, int data);
void update7SEG_Value(int index, int data);


#endif /* INC_CONTROL7SEG_H_ */
