/*
 * Dio.h
 *
 *  Created on: Sep 2, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_DIO_DIO_H_
#define INCLUDE_MCAL_DIO_DIO_H_
#include "../../../SERVICES/STD_TYPES.h"

typedef enum {

	Dio_enOk,
	Dio_enInvalidInput

}Dio_tenuErrorStatus;



//PORT DEFINE

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

// PIN DEFINE
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

// PIN DIRECTION

#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

//PIN MODE (value option)

#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

//PORT DIRECTION

#define DIO_u8_PORT_INPUT 0
#define DIO_u8_PORT_OUTPUT 255

Dio_tenuErrorStatus DIO_enuSetPinValue (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal);
u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);
Dio_tenuErrorStatus DIO_enuSetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDir);
Dio_tenuErrorStatus DIO_enuSetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortVal);
Dio_tenuErrorStatus DIO_enuSetPinDirection (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir);


#endif /* INCLUDE_MCAL_DIO_DIO_H_ */
