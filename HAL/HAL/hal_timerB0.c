/*
 * hal_timerB0.c
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */



#include <HAL/hal_ucs.h>   // Enthält SMCLK_FREQU
#include "hal_timerB0.h"
#include <msp430.h>


void hal_TimerB0Init(void)
{

    // Timer stoppen
    TB0CTL = MC__STOP | TBCLR;

   // Timer konfigurieren: SMCLK, Up Mode, Divider /8
    TB0CTL = TBSSEL__SMCLK | ID__8 | MC__UP | TBCLR;

    // Erweiterter Divider (optional)
    TB0EX0 = TBIDEX__8;

    // Compare-Wert setzen (für 0.5s Toggle)
    TB0CCR0 = TIMERB0_COUNT;
    // Interrupt für CCR0 aktivieren
    TB0CCTL0 = CCIE;
          }



#pragma vector=TIMERB0_VECTOR
__interrupt void TimerB0_ISR(void)
{
     if (TB0CCTL0 & CCIFG) {
     P8OUT ^= LCD_BL;       // Backlight umschalten (AN ↔ AUS)
     TB0CCTL0  &= ~CCIFG;   // Interrupt-Flag löschen
    }


}


