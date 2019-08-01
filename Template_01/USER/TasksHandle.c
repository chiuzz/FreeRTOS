#include "TasksHandle.h"


BaseType_t Tasks_Init(void)
{
    BaseType_t xReturn = pdPASS;
    xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,
                          (const char* )"AppTaskCreate",
                          (uint16_t )AppTaskCreate_STK_SIZE,
                          (void* )NULL,
                          (UBaseType_t )AppTaskCreate_PRIO,
                          (TaskHandle_t* )&AppTaskCreate_Handle);

    if (pdPASS == xReturn)
        vTaskStartScheduler();
    else
        return -1;
    while (1);
}



static void AppTaskCreate(void)
{
    BaseType_t xReturn = pdPASS;

    taskENTER_CRITICAL();


    xReturn = xTaskCreate((TaskFunction_t )LED1_Task,
                          (const char* )"LED1_Task",
                          (uint16_t )LED1_Task_STK_SIZE,
                          (void* )NULL,
                          (UBaseType_t )LED1_Task_PRIO,
                          (TaskHandle_t* )&LED1_Task_Handle);
    if (pdPASS == xReturn)
        printf("LED1_Task 创建成功!\r\n");


    xReturn = xTaskCreate((TaskFunction_t )LED2_Task,
                          (const char* )"LED2_Task",
                          (uint16_t )LED2_Task_STK_SIZE,
                          (void* )NULL,
                          (UBaseType_t )LED2_Task_PRIO,
                          (TaskHandle_t* )&LED2_Task_Handle);
    if (pdPASS == xReturn)
        printf("LED2_Task 创建成功!\r\n");

    vTaskDelete(AppTaskCreate_Handle);

    taskEXIT_CRITICAL();
}

static void LED1_Task(void)
{
    while(1)
    {
//        LED_RED_ON();
//        vTaskDelay(500);
//        LED_RED_OFF();
        vTaskDelay(500);
        printf("LED1_Task\r\n");
    }
}

static void LED2_Task(void)
{
    while(1)
    {
//        LED_GREEN_ON();
//        vTaskDelay(1000);
//        LED_GREEN_OFF();
        vTaskDelay(500);
        printf("LED2_Task\r\n");
    }
}
