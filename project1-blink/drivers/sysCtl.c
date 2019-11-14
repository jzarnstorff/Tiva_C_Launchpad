#include <stdint.h>
#include <stdbool.h>
#include <LM4F120H5QR.h>
#include "sysCtl.h"


void sysCtlPeripheralEnable(uint8_t gpioPortBase, bool ahb) {
    SYSCTL->RCGCGPIO |= gpioPortBase; // enable clock for gpioPortBase
    
    if(ahb)
        SYSCTL->GPIOHBCTL |= gpioPortBase; // enable AHB for gpioPortBase
}
