/*
 * hal_gpio.h
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */

#ifndef HAL_HAL_GPIO_H_
#define HAL_HAL_GPIO_H_

#include <stdint.h>
#include <msp430.h>

// Port 1
#define RPM_SENSOR       BIT3   // IN - Hall-Effekt Sensor (Drehzahl)
#define RPM_SENSOR_DIR   BIT4   // IN - Hall-Effekt Sensor (Richtung)
#define START_BUTTON     BIT7   // EN - Start-Taste (Pull-Up aktivieren)
#define STOP_BUTTON      BIT6   // EN - Stop-Taste (Pull-Up aktivieren)
#define LCD_BL             BIT0


#define LCD_BACKLIGHT_ON   (P8OUT |= LCD_BL)   // Makro: Licht AN
#define LCD_BACKLIGHT_OFF  (P8OUT &= ~LCD_BL)  // Makro: Licht AUS




typedef struct {
    unsigned char active ;
    unsigned char button;
}ButtonCom;

void hal_GpioInit(void);

#endif
