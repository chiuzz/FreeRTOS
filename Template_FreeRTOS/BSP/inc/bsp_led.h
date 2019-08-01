#ifndef __BSP_LED_H_
#define __BSP_LED_H_

typedef enum {
    LED_TURN_OFF = 0,
    LED_TURN_ON,
} LED_STA;

typedef enum {
    RED_LED=0,
    GREEN_LED,
} LEDCOLOR;

#define _LED_ON		0
#define _LED_OFF		1
#define LED_RED		PFout(9)
#define LED_GREEN	PFout(10)

#define LED_RED_ON()		LED_RED=_LED_ON
#define LED_RED_OFF()		LED_RED=_LED_OFF

#define LED_GREEN_ON()		LED_GREEN=_LED_ON
#define LED_GREEN_OFF()		LED_GREEN=_LED_OFF

#define LED_ON_OFF_TIME 25
#define LED_CNT_STEP	1

extern void Bsp_InitLed(void);
extern void led_breath(LEDCOLOR color);

#endif

