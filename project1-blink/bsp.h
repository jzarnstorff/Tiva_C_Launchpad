#ifndef BSP_H
#define BSP_H

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void delay(const int count);
void toggleLED(const int led_color);
void LED_GPIOF_AHB_init(void);

#endif /* BSP_H */
