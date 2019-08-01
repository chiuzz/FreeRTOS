#ifndef __TASKSHANDLE_H_
#define __TASKSHANDLE_H_


#include "FreeRTOS.h"
#include "task.h"
#include "..\BSP\bsp.h"

#define	AppTaskCreate_STK_SIZE 512
#define	AppTaskCreate_PRIO 1
static TaskHandle_t AppTaskCreate_Handle = NULL;

#define	LED1_Task_STK_SIZE 512
#define LED1_Task_PRIO 2
static TaskHandle_t LED1_Task_Handle = NULL;

#define LED2_Task_STK_SIZE 512
#define LED2_Task_PRIO 3
static TaskHandle_t LED2_Task_Handle = NULL;

BaseType_t Tasks_Init(void);
static void AppTaskCreate(void);
static void LED1_Task(void);
static void LED2_Task(void);

#endif

