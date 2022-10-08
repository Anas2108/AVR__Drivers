/*
 * GIE.c
 *
 *  Created on: Sep 22, 2022
 *      Author: ANOOS
 */

#include "../../../INCLUDE/MCAL/GIE/GIE.h"
#include "../../../INCLUDE/MCAL/GIE/GIE_prv.h"
#include "../../../SERVICES/bit_utilies.h"


void GIE_voidGlobalInterruptEnable(void)
{

SET_BIT(SREG,GIE_SREG_PIN);

}

void GIE_voidGlobalInterruptDisable(void)
{

CLR_BIT(SREG,GIE_SREG_PIN);

}
