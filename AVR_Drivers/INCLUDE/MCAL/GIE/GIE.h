/*
 * Gie.h
 *
 *  Created on: Sep 22, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_GIE_GIE_H_
#define INCLUDE_MCAL_GIE_GIE_H_
#include "../../../SERVICES/STD_TYPES.h"

#define GIE_SREG_PIN 7

void GIE_voidGlobalInterruptEnable(void);


void GIE_voidGlobalInterruptDisable(void);

#endif /* INCLUDE_MCAL_GIE_GIE_H_ */
