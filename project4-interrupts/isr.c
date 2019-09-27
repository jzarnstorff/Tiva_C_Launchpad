#include <LM4F120H5QR.h>
#include "bsp.h"

void Timer0AHandler(void) {
    TIMER0->ICR |= (1U << 0);
    GPIOF_AHB->DATA ^= LED_GREEN;
}
