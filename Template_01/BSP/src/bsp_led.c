#include "bsp.h"

void Bsp_InitLed(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
    LED_RED_OFF();
    LED_GREEN_OFF();
}

static LED_STA led_sta=LED_TURN_ON;
u16 LedOnCnt=0;
u16 LedCnt=0;

void led_breath(LEDCOLOR color)
{
    if(LedCnt<LedOnCnt) {
        if(color==RED_LED)
            LED_RED_ON();
        else
            LED_GREEN_ON();
    }
    else {
        if(color==RED_LED)
            LED_RED_OFF();
        else
            LED_GREEN_OFF();
    }
    LedCnt++;

    switch(led_sta)
    {
    case LED_TURN_ON:
        if(LedCnt>=LED_ON_OFF_TIME) {
            LedCnt=0;
            if(LedOnCnt>=LED_ON_OFF_TIME)
            {
                led_sta=LED_TURN_OFF;
                break;
            }
            LedOnCnt+=LED_CNT_STEP;
            if(LedOnCnt>=LED_ON_OFF_TIME)
            {
                LedOnCnt=LED_ON_OFF_TIME;
            }
        }
        break;

    case LED_TURN_OFF:
        if(LedCnt>=LED_ON_OFF_TIME) {
            LedCnt=0;
            if(LedOnCnt<=0)
            {
                led_sta=LED_TURN_ON;
                break;
            }
            if(LedOnCnt<LED_CNT_STEP)
            {
                LedOnCnt=0;
            }
            else
            {
                LedOnCnt-=LED_CNT_STEP;
            }
        }
        break;

    default:
        break;
    }
}





