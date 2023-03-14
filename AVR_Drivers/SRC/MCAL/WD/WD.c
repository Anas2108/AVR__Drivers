/*
 * WD.c
 *
 *  Created on: Oct 8, 2022
 *      Author: ANOOS
 */


#include "../../../INCLUDE/MCAL/WD/WD.h"
#include "../../../INCLUDE/MCAL/WD/WD_prv.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"
#include "../../../SERVICES/bit_utilies.h"


void WD_voidSleepTime(u8 Copy_u8TimeOfSleep)
{

switch (Copy_u8TimeOfSleep)
  {
case WD_SLEEP_16_ms:    CLR_BIT(WDTCR,2); CLR_BIT(WDTCR,1); CLR_BIT(WDTCR,0);     break;
case WD_SLEEP_32_ms:    CLR_BIT(WDTCR,2); CLR_BIT(WDTCR,1); SET_BIT(WDTCR,0);     break;
case WD_SLEEP_65_ms:    CLR_BIT(WDTCR,2); SET_BIT(WDTCR,1); CLR_BIT(WDTCR,0);     break;
case WD_SLEEP_130_ms:   CLR_BIT(WDTCR,2); SET_BIT(WDTCR,1); SET_BIT(WDTCR,0);     break;
case WD_SLEEP_260_ms:   SET_BIT(WDTCR,2); CLR_BIT(WDTCR,1); CLR_BIT(WDTCR,0);     break;
case WD_SLEEP_520_ms:   SET_BIT(WDTCR,2); CLR_BIT(WDTCR,1); SET_BIT(WDTCR,0);     break;
case WD_SLEEP_1000_ms:  SET_BIT(WDTCR,2); SET_BIT(WDTCR,1); CLR_BIT(WDTCR,0);     break;
case WD_SLEEP_2100_ms:  SET_BIT(WDTCR,2); SET_BIT(WDTCR,1); SET_BIT(WDTCR,0);     break;

   }

}


void WD_voidWatchDogEnable(void)
{
	SET_BIT(WDTCR,3);

}

void WD_voidWatchDogDisable(void)
{
	CLR_BIT(WDTCR,3);
	SET_BIT(WDTCR,4);

}
