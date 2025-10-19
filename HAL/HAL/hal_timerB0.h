/*
 * hal_timerB0.h
 *
 *  Created on: 19 Oct 2025
 *      Author: fn
 */


#ifndef HAL_TIMERB0_H_
#define HAL_TIMERB0_H_


#include <stdint.h>
#include <msp430.h>
#include "hal_gpio.h"
#include "hal_ucs.h"


#define TIMERB0_TOGGLE_FREQ_HZ   2
#define TIMERB0_DIVIDER          64
#define TIMERB0_COUNT        ((SMCLK_FREQU / TIMERB0_DIVIDER) / TIMERB0_TOGGLE_FREQ_HZ -1 )
void hal_TimerB0Init(void);


#endif /* HAL_TIMERB0_H_ */
