#include <HAL/hal_general.h>
#include <msp430.h> 
#include "HAL/hal_timerB0.h"
#include "HAL/hal_ucs.h"

/**
 * main.c
 */



 int a = 12;
 int b = 15;
 float c = 1.6;
 float d = 1.9;


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    hal_Init();

     while(1)
     {
         //Integer Berechnung
         {
  LCD_BACKLIGHT_ON;
 int result_int = a * b ;
 LCD_BACKLIGHT_OFF;
         }

         {

       // Floating berechnung
  LCD_BACKLIGHT_ON;
 float result_float = c * d;
  LCD_BACKLIGHT_OFF;

         }
        }
    }




