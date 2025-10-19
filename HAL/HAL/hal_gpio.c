/*
 * hal_gpio.c
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */


#include <HAL/hal_gpio.h>

extern ButtonCom CCbutton;

void hal_GpioInit(void)
{

     // PORT 1, Eingänge
    P1DIR &= ~(RPM_SENSOR | RPM_SENSOR_DIR | START_BUTTON | STOP_BUTTON);
    P1REN |= (START_BUTTON | STOP_BUTTON); // Pull-up/down aktivieren
    P1OUT |= (START_BUTTON | STOP_BUTTON); // Pull-up auswählen

    // Interrupts aktivieren
    P1IE |= (START_BUTTON | STOP_BUTTON); // Interrupt enable
    P1IES |=  (START_BUTTON | STOP_BUTTON); // steigende Flanke
    P1IFG &= ~(START_BUTTON | STOP_BUTTON);   // Flags löschen

    // LCD Backlight (P8.0)
    P8DIR |= LCD_BL;
    P8OUT &= ~LCD_BL;

   // port 1 Interrupt
    P1DIR &= ~BIT1;      // P1.3 als Eingang
    P1REN |= BIT1;       // Pull-Up/Down aktivieren
    P1OUT |= BIT1;       // Pull-Up auswählen
    P1IE  |= BIT1;       // Interrupt aktivieren
    P1IES &= ~BIT1;      // Steigende Flanke
    P1IFG &= ~BIT1;      // Interrupt-Flag löschen

  //XT2 aktivieren P3.5
    P5SEL |= BIT3 + BIT3;
    P3DIR |= BIT7;


    // Port 1: Bits 0, 1, 2 sind unbenutzt
    P1DIR |= (BIT0 | BIT1 | BIT2);
    P1OUT &= ~(BIT0 | BIT1 | BIT2);

    // Port 8: Alle anderen Bits außer BIT2 (LCD_BL) sind unbenutzt
    P8DIR |= ( BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7 );
    P8OUT &= ~(BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);

}
  // port 1 interrupt
#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void)
{
    switch (P1IFG) {
    case START_BUTTON:
        CCbutton.active = 1;
        CCbutton.button = START_BUTTON; // Start
        P1IFG &= ~START_BUTTON;
        break;


    case STOP_BUTTON:
        CCbutton.active = 1;
        CCbutton.button = STOP_BUTTON ; // Stop
        P1IFG &= ~STOP_BUTTON;
        break;
    default:
        P1IFG = 0x00;
        break;
    }
}
