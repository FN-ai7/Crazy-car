/*
 * hal_wdt.c
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */

#include <HAL/hal_wdt.h>
#include <msp430.h>


void hal_WdtInit(void)
{

    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
}

