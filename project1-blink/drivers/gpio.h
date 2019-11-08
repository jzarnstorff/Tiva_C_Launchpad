#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO_PIN_0             (1U << 0)
#define GPIO_PIN_1             (1U << 1)
#define GPIO_PIN_2             (1U << 2)
#define GPIO_PIN_3             (1U << 3)
#define GPIO_PIN_4             (1U << 4)
#define GPIO_PIN_5             (1U << 5)
#define GPIO_PIN_6             (1U << 6)
#define GPIO_PIN_7             (1U << 7)


/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define GPIOA_BASE             0x40004000UL
#define GPIOB_BASE             0x40005000UL
#define GPIOC_BASE             0x40006000UL
#define GPIOD_BASE             0x40007000UL
#define GPIOE_BASE             0x40024000UL
#define GPIOF_BASE             0x40025000UL
#define GPIOA_AHB_BASE         0x40058000UL
#define GPIOB_AHB_BASE         0x40059000UL
#define GPIOC_AHB_BASE         0x4005A000UL
#define GPIOD_AHB_BASE         0x4005B000UL
#define GPIOE_AHB_BASE         0x4005C000UL
#define GPIOF_AHB_BASE         0x4005D000UL


/* ================================================================================ */
/* ================             Function prototypes                ================ */
/* ================================================================================ */

void GPIODirModeSet(const uint32_t gpioPortBase, const uint8_t gpioPins, const uint8_t gpioDir);
void GPIOTogglePin(const uint32_t gpioPortBase, const uint8_t pin);
void GPIOWrite(const uint32_t gpioPortBase, const uint8_t gpioPins, const uint8_t value);

#endif /* GPIO_H */
