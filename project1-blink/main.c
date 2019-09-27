#include "bsp.h"

/*
 * main.c
 */
int main(void) {

    LED_GPIOF_AHB_init();

	while(1) {
	    toggleLED(LED_BLUE);
		delay(2000000);
	}

	return 0;
}
