/*
 * hal_general.c
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */

#include <HAL/hal_general.h>
#include <HAL/hal_gpio.h>
#include <HAL/hal_pmm.h>
#include <HAL/hal_ucs.h>
#include <HAL/hal_wdt.h>
#include <msp430.h>
#include "hal_timerB0.h"

ButtonCom CCbutton;

void hal_Init(void)
{
    // Watchdog Timer initialisieren
        hal_WdtInit();

    // Power Management Module initialisieren
        HAL_PMM_Init();

    // GPIO-Pins initialisieren
        hal_GpioInit();

    // Takt auf 20 MHz MCLK, 2.5 MHz SMCLK
        hal_ucsInit();

   //  TimerB0 initialisieren
        hal_TimerB0Init();

   // Globale Interrupts aktivieren
   __enable_interrupt();
}
