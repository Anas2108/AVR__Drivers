/*
 * EXTI_prv.h
 *
 *  Created on: Sep 22, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_PRV_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRV_H_



#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)
#define GICR *((volatile u8*) 0x5B)
#define GIFR *((volatile u8*) 0x5A)




#endif /* INCLUDE_MCAL_EXTI_EXTI_PRV_H_ */
