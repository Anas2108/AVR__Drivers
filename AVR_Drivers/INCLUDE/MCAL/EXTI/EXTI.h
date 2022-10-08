/*
 * EXTI.h
 *
 *  Created on: Sep 22, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_H_
#define INCLUDE_MCAL_EXTI_EXTI_H_
#include "../../../SERVICES/STD_TYPES.h"

#define EXTI_INT_0 0
#define EXTI_INT_1 1
#define EXTI_INT_2 2

//Modes of INT0 //PD2

#define EXTI_INT_0_LOW_LEVEL 0
#define EXTI_INT_0_LOGICAL_CHANGE 1
#define EXTI_INT_0_FALLING_EDGE 2
#define EXTI_INT_0_RISING_EDGE 3

//Modes of INT1 //PD3

#define EXTI_INT_1_LOW_LEVEL 0
#define EXTI_INT_1_LOGICAL_CHANGE 1
#define EXTI_INT_1_FALLING_EDGE 2
#define EXTI_INT_1_RISING_EDGE 3

//Modes of INT2 //PB2
#define EXTI_INT_2_FALLING_EDGE 2
#define EXTI_INT_2_RISING_EDGE 3

// GICR>>PIE of 3 INT

#define EXTI_INT_0_GICR 6
#define EXTI_INT_1_GICR 7
#define EXTI_INT_2_GICR 5

void EXTI_voidEnable(u8 Copy_u8ExtIntNum,u8 Copy_u8EdgeIntSource);

void EXTI_voidDisable(u8 Copy_u8ExtIntNum);

#endif /* INCLUDE_MCAL_EXTI_EXTI_H_ */
