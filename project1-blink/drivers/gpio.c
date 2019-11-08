#include <stdint.h>
#include <stdbool.h>
#include <LM4F120H5QR.h>
#include "gpio.h"

#define GPIOA_STRUCT(GPIO_BASE)         ((GPIOA_Type *) GPIO_BASE)


static bool _GPIOBaseIsValid(uint32_t gpioPortBase) {
    return((gpioPortBase == GPIOA_BASE) || (gpioPortBase == GPIOA_AHB_BASE) ||
           (gpioPortBase == GPIOB_BASE) || (gpioPortBase == GPIOB_AHB_BASE) ||
           (gpioPortBase == GPIOC_BASE) || (gpioPortBase == GPIOC_AHB_BASE) ||
           (gpioPortBase == GPIOD_BASE) || (gpioPortBase == GPIOD_AHB_BASE) ||
           (gpioPortBase == GPIOE_BASE) || (gpioPortBase == GPIOE_AHB_BASE) ||
           (gpioPortBase == GPIOF_BASE) || (gpioPortBase == GPIOF_AHB_BASE));
}


void GPIODirModeSet(const uint32_t gpioPortBase, const uint8_t gpioPins, const uint8_t gpioDir) {
    
    if (_GPIOBaseIsValid(gpioPortBase)) {
        GPIOA_STRUCT(gpioPortBase)->DIR |= gpioDir;  /* set direction as output */
        GPIOA_STRUCT(gpioPortBase)->DEN |= gpioPins; /* set digital enables */
    }
}


void GPIOTogglePin(const uint32_t gpioPortBase, const uint8_t pin) {

    if (_GPIOBaseIsValid(gpioPortBase))
        GPIOA_STRUCT(gpioPortBase)->DATA ^= pin;
}


void GPIOWrite(const uint32_t gpioPortBase, const uint8_t gpioPins, const uint8_t value) {
    
    if (_GPIOBaseIsValid(gpioPortBase))
        GPIOA_STRUCT(gpioPortBase)->DATA_BITS[gpioPins] = value;
}
