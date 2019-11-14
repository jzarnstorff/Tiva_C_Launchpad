#ifndef SYSCTL_H
#define SYSCTL_H

#include <stdint.h>

#define SYSCTL_GPIO_PORTA      (1U << 0)
#define SYSCTL_GPIO_PORTB      (1U << 1)
#define SYSCTL_GPIO_PORTC      (1U << 2)
#define SYSCTL_GPIO_PORTD      (1U << 3)
#define SYSCTL_GPIO_PORTE      (1U << 4)
#define SYSCTL_GPIO_PORTF      (1U << 5)


/* ================================================================================ */
/* ================             Function prototypes                ================ */
/* ================================================================================ */

void sysCtlPeripheralEnable(uint8_t gpioPortBase, bool ahb);

#endif /* SYSCTL_H */
