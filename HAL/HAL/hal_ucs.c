/*
 * hal_ucs.c
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */


// hal_ucs.c (Auszug)
// hal_ucs.c (Auszug)

#include <HAL/hal_ucs.h>
#include <msp430.h>

void hal_ucsInit(void)
{
    // XT2 einschalten
    UCSCTL6 &= ~XT2OFF;

    // FLL Referenz = REFO
    UCSCTL3 |= SELREF_2;
    UCSCTL4 |= SELA_2; // ACLK = REFO

    // Warten bis Oszillator stabil
    while (SFRIFG1 & OFIFG)
    {
        UCSCTL7 &= ~(XT2OFFG + DCOFFG + XT1HFOFFG + XT1LFOFFG);
        SFRIFG1 &= ~OFIFG;
    }

    // Drive-Strength anpassen
    UCSCTL6 &= ~XT2DRIVE_3;

    // SMCLK und MCLK = XT2
    UCSCTL4 |= SELS_5 + SELM_5;

    // SMCLK-Teiler /8 (20 MHz / 8 = 2.5 MHz)
    UCSCTL5 |= DIVS__8;
}



