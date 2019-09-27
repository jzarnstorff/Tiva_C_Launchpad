#include "bsp.h"

/*
 * main.c
 */
int main(void) {

    LED_GPIOF_AHB_init();
    timer0_A_init(0x00F42400); // 16,000,000

	while(1) {
    }

	return 0;
}
