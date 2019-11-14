#include <LM4F120H5QR.h>
#include "bsp.h"

void delay(int count) {
	int clockCounter = 0;
	while(clockCounter++ < count);
}

void toggleLED(int led_color) {
    GPIOF_AHB->DATA ^= led_color;
}

void LED_GPIOF_AHB_init(void) {
    SYSCTL->RCGCGPIO  |= (1U << 5); // enable clock for GPIOF
    SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF
    GPIOF_AHB->DIR    |= (LED_GREEN | LED_BLUE | LED_RED); // set direction as output
    GPIOF_AHB->DEN    |= (LED_GREEN | LED_BLUE | LED_RED); // set digital enables
}

void timer0_A_init(int start_val) {
    /* 11.4 Initialization and Configuration
       To use a GPTM, the appropriate TIMERn bit must be set in the RCGCTIMER */
    SYSCTL->RCGCTIMER |= (1U << 0);

    /* Ensure the timer is disabled (the TnEN bit in the GPTMCTL register 
     is cleared) before making any changes. */
    TIMER0->CTL &= ~(1U << 0);

    /* Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000. */
    TIMER0->CFG = 0x00000000;

    /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR) */
    TIMER0->TAMR = (0x2 << 0);

    /* Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR 
       register to select whether to capture the value of the free-running timer at 
       time-out, use an external trigger to start counting, configure an additional 
       trigger or interrupt, and count up or down. */
    TIMER0->TAMR &= ~(1U << 4);

    /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR) */
    TIMER0->TAILR = start_val; // 16,000,000
    
    /* If interrupts are required, set the appropriate bits in the GPTM Interrupt 
       Mask Register (GPTMIMR). */
    TIMER0->IMR |= (1U << 0);
    // NVIC->ISER[0] |= (1U << 19); same as function below
    NVIC_EnableIRQ(TIMER0A_IRQn); // defined in LM4F120H5QR.h

    /* Set the TnEN bit in the GPTMCTL register to enable the timer and start counting. */
    TIMER0->CTL |= (1U << 0);
}
