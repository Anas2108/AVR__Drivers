/*
 * Led.h
 *
 *  Created on: Sep 4, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_HAL_LED_LED_H_
#define INCLUDE_HAL_LED_LED_H_

#include "../../../SERVICES/STD_TYPES.h"





typedef struct {

	u8 portId;
	u8 pinId;
	u8 Active_State;
	u8 Curent_State;


}Led_str;

//FOR active high and active low

#define LED_u8_Active_High 1

#define LED_u8_Active_Low 0


//for the value of active H OR L
#define LED_u8_Active_Low_L 1
#define LED_u8_Active_Low_H 0
#define LED_u8_Active_High_H 1
#define LED_u8_Active_High_L 0
//PORT DEFINE

//#define DIO_u8_PORTA 0
//#define DIO_u8_PORTB 1
//#define DIO_u8_PORTC 2
//#define DIO_u8_PORTD 3
//
//// PIN DEFINE
//#define DIO_u8_PIN0 0
//#define DIO_u8_PIN1 1
//#define DIO_u8_PIN2 2
//#define DIO_u8_PIN3 3
//#define DIO_u8_PIN4 4
//#define DIO_u8_PIN5 5
//#define DIO_u8_PIN6 6
//#define DIO_u8_PIN7 7
//
//// PIN DIRECTION
//
//#define DIO_u8_INPUT 0
//#define DIO_u8_OUTPUT 1
//
////PIN MODE (value option)
//
//#define DIO_u8_HIGH 1
//#define DIO_u8_LOW 0
//
////PORT DIRECTION
//
//#define DIO_u8_PORT_INPUT 0
//#define DIO_u8_PORT_OUTPUT 255

void Led_voidTurnOn(Led_str * Add_ledStrPointer);
void Led_voidSetLedDir(Led_str *Add_ledStrPointer);
void Led_voidTurnOff(Led_str * Add_ledStrPointer);
void Led_voidToggle(Led_str * Add_ledStrPointer);





#endif /* INCLUDE_HAL_LED_LED_H_ */
