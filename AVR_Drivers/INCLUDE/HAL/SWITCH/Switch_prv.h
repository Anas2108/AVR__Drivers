/*
 * Segment_prv.h
 *
 *  Created on: Sep 6, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_HAL_SEGMENT_SEGMENT_PRV_H_
#define INCLUDE_HAL_SEGMENT_SEGMENT_PRV_H_



#define DDRA_Register *((volatile u8*) 0x3A)
#define PORTA_Register *((volatile u8*) 0x3B)
#define PINA_Register *((volatile u8*) 0x39)



#define DDRB_Register *((volatile u8*) 0x37)
#define PORTB_Register *((volatile u8*) 0x38)
#define PINB_Register *((volatile u8*) 0x36)


#define DDRC_Register *((volatile u8*) 0x34)
#define PORTC_Register *((volatile u8*) 0x35)
#define PINC_Register *((volatile u8*) 0x33)


#define DDRD_Register *((volatile u8*) 0x31)
#define PORTD_Register *((volatile u8*) 0x32)
#define PIND_Register *((volatile u8*) 0x30)




#endif /* INCLUDE_HAL_SEGMENT_SEGMENT_PRV_H_ */
