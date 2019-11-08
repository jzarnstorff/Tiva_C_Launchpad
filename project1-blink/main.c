#include <stdbool.h>
#include "bsp.h"
#include "drivers/gpio.h"
#include "drivers/sysCtl.h"

/*
 * main.c
 */
int main(void) {

    sysCtlPeripheralEnable(SYSCTL_GPIO_PORTF, true); /* Enable clock for GPIO Port F */
    GPIODirModeSet(GPIOF_AHB_BASE, GPIO_PIN_3, GPIO_PIN_3); /* Set GPIO pin as output */

	while(1) {
	    GPIOTogglePin(GPIOF_AHB_BASE, GPIO_PIN_3);
		delay(2000000);
	}

	return 0;
}
