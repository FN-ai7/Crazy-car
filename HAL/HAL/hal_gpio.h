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
#define I2C_INT_MOTION   BIT5   // OUT - Interrupt von MPU-9250 (Motion Detection)
#define START_BUTTON     BIT6   // EN - Start-Taste (Pull-Up aktivieren)
#define STOP_BUTTON      BIT7   // EN - Stop-Taste (Pull-Up aktivieren)


#define LCD_BL             BIT0               // P8.0 - LCD Backlight
#define LCD_BACKLIGHT_ON   (P8OUT |= LCD_BL)   // Makro: Licht AN
#define LCD_BACKLIGHT_OFF  (P8OUT &= ~LCD_BL)  // Makro: Licht AUS




typedef struct {
    unsigned char active ;
    unsigned char button;
}ButtonCom;

void hal_GpioInit(void);

#endif /* HAL_HAL_GPIO_H_ */
