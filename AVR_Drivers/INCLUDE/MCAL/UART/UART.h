/*
 * UART.h
 *
 *  Created on: Oct 8, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_UART_UART_H_
#define INCLUDE_MCAL_UART_UART_H_

#include "../../../SERVICES/STD_TYPES.h"

/* USART Mode Select*/

#define USART_MODE_SELECT_ASYNCHRONOUS 0
#define USART_MODE_SELECT_SYNCHRONOUS 1

/* Parity Mode*/

#define USART_PARITY_MODE_DISABLE 0
#define USART_PARITY_MODE_EVEN 1
#define USART_PARITY_MODE_ODD 2


/* Stop Bit Select*/

#define USART_STOP_1_BIT 0
#define  USART_STOP_2_BIT 1

/*Data size*/

#define USART_DATA_SIZE_5_BIT 0
#define USART_DATA_SIZE_6_BIT 1
#define USART_DATA_SIZE_7_BIT 2
#define USART_DATA_SIZE_8_BIT 3
#define USART_DATA_SIZE_9_BIT 4


/*Clock Polarity*/
//(FOR SYNCHRONOUS MODE ONLY! )
#define USART_CLK_POLARITY_1 0  //Transmit data at Rising XCK Edge Receive Data at Falling XCK Edge   (XCK:the name of the clk )
#define USART_CLK_POLARITY_2 1  //Receive data at Rising XCK Edge Transmit Data at Falling XCK Edge
#define USART_CLK_POLARITY_DISABLE 2

/*Double the USART Transmission Speed*/

#define USART_DOUBLE_SPEED_ENABLE 1
#define USART_DOUBLE_SPEED_DISABLE 0



/*Baud Rate (bps)  (FOR 8MHZ only)*/
#define USART_BAUD_RATE_2400 0
#define USART_BAUD_RATE_4800 1
#define USART_BAUD_RATE_9600 2
#define USART_BAUD_RATE_14400 3
#define USART_BAUD_RATE_19200 4
#define USART_BAUD_RATE_28800 5
#define USART_BAUD_RATE_38400 6
#define USART_BAUD_RATE_57600 7
#define USART_BAUD_RATE_76800 8




/*USART struct */

typedef struct {

	u8 baud_rate;
	u8 double_speed;
	u8 USART_mode;
	u8 Clock_Polarity;
	u8 Parity_Mode;
	u8 num_of_Stop_bits;
	u8 data_size;
}USART_str;




/* To adjust the USART settings*/
void UART_voidInit(USART_str * Add_ptrPointerUSART);

/*To send data*/
void UART_voidSendChar(u8 data);

/*To Receive data*/
u8 UART_u8GetChar(void);

#endif /* INCLUDE_MCAL_UART_UART_H_ */
