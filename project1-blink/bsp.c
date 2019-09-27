#include <LM4F120H5QR.h>
#include "bsp.h"

void delay(const int count) {
	int clockCounter = 0;
	while(clockCounter++ < count);
}

void toggleLED(const int led_color) {
    GPIOF_AHB->DATA ^= led_color;
}

void LED_GPIOF_AHB_init(void) {
    SYSCTL->RCGCGPIO  |= (1U << 5); // enable clock for GPIOF
    SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF
    GPIOF_AHB->DIR    |= (LED_GREEN | LED_BLUE | LED_RED); // set direction as output
    GPIOF_AHB->DEN    |= (LED_GREEN | LED_BLUE | LED_RED); // set digital enables
}
