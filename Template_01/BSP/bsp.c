#include "bsp.h"

void Bsp_Init(void)
{
    uart_init(115200);
    delay_init(168);
    Bsp_InitLed();
}

