/*
 * UART_prv.h
 *
 *  Created on: Oct 8, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_UART_UART_PRV_H_
#define INCLUDE_MCAL_UART_UART_PRV_H_


#define UDR_T *((volatile u8*) 0x2C)
#define UDR_R *((volatile u8*) 0x2C)
#define UCSRA *((volatile u8*) 0x2B)
#define UCSRB *((volatile u8*) 0x2A)
#define UCSRC *((volatile u8*) 0x40)
#define UBRRL *((volatile u8*) 0x29)
#define UBRRH *((volatile u8*) 0x40)

#endif /* INCLUDE_MCAL_UART_UART_PRV_H_ */
