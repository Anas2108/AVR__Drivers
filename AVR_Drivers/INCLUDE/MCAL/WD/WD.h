/*
 * WD.h
 *
 *  Created on: Oct 8, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_WD_WD_H_
#define INCLUDE_MCAL_WD_WD_H_

#include "../../../SERVICES/STD_TYPES.h"

#define WD_SLEEP_16_ms 0
#define WD_SLEEP_32_ms 1
#define WD_SLEEP_65_ms 2
#define WD_SLEEP_130_ms 3
#define WD_SLEEP_260_ms 4
#define WD_SLEEP_520_ms 5
#define WD_SLEEP_1000_ms 6
#define WD_SLEEP_2100_ms 7

void WD_voidSleepTime(u8 Copy_u8TimeOfSleep);

void WD_voidWatchDogEnable(void);
void WD_voidWatchDogDisable(void);

#endif /* INCLUDE_MCAL_WD_WD_H_ */
