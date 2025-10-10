#include "gpio.h"
#include "system_clock.h"
#include "tasks.h"
#include "rtos.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    GPIO_Init();
    Tasks_Init();
    vTaskStartScheduler();
}