/* Main program */

#include <stdlib.h>
#include <avr/io.h>

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"


#define TASK_PRIORITY           ( configMAX_PRIORITIES - 1 )


void TaskFn(void* parameter)
{
    DDRB |= (1 << 5);

    while(1)
    {
        PORTB ^= (1 << 5);

        volatile uint32_t i;
        for(i = 0; i < 100000; ++i)
        {
            (void) i;
        }
    }
}

void TaskFn2(void* parameter)
{
    DDRB |= (1 << 4);

    while(1)
    {
        PORTB ^= (1 << 4);

        volatile uint32_t i;
        for(i = 0; i < 100000; ++i)
        {
            (void) i;
        }
    }
}

int main(void)
{
    TaskHandle_t xHandle;
    TaskHandle_t xHandle2;
    xTaskCreate( TaskFn,  "Test", 256, NULL, TASK_PRIORITY,  &xHandle);
    xTaskCreate(TaskFn2, "Test2", 256, NULL, TASK_PRIORITY, &xHandle2);

    vTaskStartScheduler();
    for(;;);

    return 0;
}
