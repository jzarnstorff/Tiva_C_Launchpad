#include <stdint.h>
#include "bsp.h"

void delay(const uint32_t count) {
	uint32_t clockCounter = 0;
	while(clockCounter++ < count);
}
