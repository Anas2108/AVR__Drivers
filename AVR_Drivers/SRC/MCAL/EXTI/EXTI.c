/*
 * EXTI.c
 *
 *  Created on: Sep 22, 2022
 *      Author: ANOOS
 */
#include "../../../INCLUDE/MCAL/EXTI/EXTI.h"
#include "../../../INCLUDE/MCAL/EXTI/EXTI_prv.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"
#include "../../../SERVICES/bit_utilies.h"
#include "util/delay.h"
void EXTI_voidEnable(u8 Copy_u8ExtIntNum,u8 Copy_u8EdgeIntSource)
{

 switch(Copy_u8ExtIntNum)
  {
 case EXTI_INT_0: SET_BIT(GICR, EXTI_INT_0_GICR);
		 switch(Copy_u8EdgeIntSource)
		 {
		 case EXTI_INT_0_LOW_LEVEL: CLR_BIT(MCUCR,1); CLR_BIT(MCUCR,0); break;
		 case EXTI_INT_0_LOGICAL_CHANGE: CLR_BIT(MCUCR,1); SET_BIT(MCUCR,0); break;
		 case EXTI_INT_0_FALLING_EDGE: SET_BIT(MCUCR,1); CLR_BIT(MCUCR,0); break;
		 case EXTI_INT_0_RISING_EDGE: SET_BIT(MCUCR,1); SET_BIT(MCUCR,0); break;

		 }

		  break;


 case EXTI_INT_1: SET_BIT(GICR, EXTI_INT_1_GICR);
 switch(Copy_u8EdgeIntSource)
		 {
		 case EXTI_INT_1_LOW_LEVEL: CLR_BIT(MCUCR,3); CLR_BIT(MCUCR,2); break;
		 case EXTI_INT_1_LOGICAL_CHANGE:  CLR_BIT(MCUCR,3); SET_BIT(MCUCR,2); break;
		 case EXTI_INT_1_FALLING_EDGE: SET_BIT(MCUCR,3); CLR_BIT(MCUCR,2); break;
		 case EXTI_INT_1_RISING_EDGE: SET_BIT(MCUCR,3); SET_BIT(MCUCR,2); break;

		 }

 break;

 case EXTI_INT_2: SET_BIT(GICR, EXTI_INT_2_GICR);
 switch(Copy_u8EdgeIntSource)
		 {

		 case EXTI_INT_2_FALLING_EDGE:  CLR_BIT(MCUCR,6); break;
		 case EXTI_INT_2_RISING_EDGE: SET_BIT(MCUCR,6);  break;

		 }

 break;



  }
}

 /////////////////////////////////////////////

 void EXTI_voidDisable(u8 Copy_u8ExtIntNum)
 {


	 switch( Copy_u8ExtIntNum)
	 {
	 case EXTI_INT_0: CLR_BIT(GICR, EXTI_INT_0_GICR); break;
	 case EXTI_INT_1: CLR_BIT(GICR, EXTI_INT_1_GICR); break;
	 case EXTI_INT_2: CLR_BIT(GICR, EXTI_INT_2_GICR); break;


	 }


 }


//////////////////////////////////ISR FUNCTION////////////////////////////////////

 void __vector_1(void) __attribute__((signal));
  void __vector_1(void)
  {

  	_delay_ms(200);

  	TGL_BIT(PORTA_Register,0);


  	_delay_ms(200);


  }


