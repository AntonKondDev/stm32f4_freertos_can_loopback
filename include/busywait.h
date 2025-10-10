#pragma once
#include "stm32f4xx.h"
#include <stdint.h>

static inline void busy_ms(uint32_t ms)
{
    /* Точный busy-wait через DWT->CYCCNT */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;   // Разрешить DWT
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;              // Включить счётчик
    uint32_t start = DWT->CYCCNT;
    uint32_t ticks = (SystemCoreClock / 1000U) * ms;
    while ((DWT->CYCCNT - start) < ticks) { __NOP(); }
}
