#include "mode.h"
void mode1Run() {
	switch (state) {
	case init:
		setTimer1(greenTime * 1000);
		ModeofLED = redTime;
		ValueofLED = greenTime;
		setRed1();
		setGreen2();
		state = state1;
		break;
	case state1:
		if (timer1_flag == 1) {
			setTimer1(yellowTime * 1000);
			setYellow2();
			ValueofLED = yellowTime;
			state = state2;
		}
		break;
	case state2:
		if (timer1_flag == 1) {
			setTimer1(greenTime * 1000);
			setGreen1();
			setRed2();
			ModeofLED = greenTime;
			ValueofLED = redTime;
			state = state3;
		}
		break;
	case state3:
		if (timer1_flag == 1) {
			setTimer1(yellowTime * 1000);
			setYellow1();
			ModeofLED = yellowTime;
			state = state4;
		}
		break;
	case state4:
		if (timer1_flag == 1) {
			setTimer1(greenTime * 1000);
			setRed1();
			setGreen2();
			ModeofLED = redTime;
			ValueofLED = greenTime;
			state = state1;
		}
		break;
	default:
		break;
	}
}

