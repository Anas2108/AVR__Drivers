/*
 * UART.c
 *
 *  Created on: Oct 8, 2022
 *      Author: ANOOS
 */

#include "../../../INCLUDE/MCAL/UART/UART.h"
#include "../../../INCLUDE/MCAL/UART/UART_prv.h"
#include "../../../SERVICES/bit_utilies.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"

u8 reg_copy=0;

void UART_voidInit(USART_str * Add_ptrPointerUSART){
//to set baud rate
switch(Add_ptrPointerUSART->double_speed)
  {
case USART_DOUBLE_SPEED_DISABLE: CLR_BIT(UCSRA,1);

     switch(Add_ptrPointerUSART->baud_rate)
     {
     case USART_BAUD_RATE_2400 : UBRRL= 207; UBRRH=0; break;
     case USART_BAUD_RATE_4800 : UBRRL= 103; UBRRH=0; break;
     case USART_BAUD_RATE_9600 : UBRRL= 51; UBRRH=0; break;
     case USART_BAUD_RATE_14400 : UBRRL= 34; UBRRH=0; break;
     case USART_BAUD_RATE_19200 : UBRRL= 25; UBRRH=0; break;
     case USART_BAUD_RATE_28800 : UBRRL= 16; UBRRH=0; break;
     case USART_BAUD_RATE_38400 : UBRRL= 12; UBRRH=0; break;
     case USART_BAUD_RATE_57600 : UBRRL= 8; UBRRH=0; break;
     case USART_BAUD_RATE_76800 : UBRRL= 6; UBRRH=0; break;

     } break;



     case USART_DOUBLE_SPEED_ENABLE: SET_BIT(UCSRA,1);

          switch(Add_ptrPointerUSART->baud_rate)
          {
          case USART_BAUD_RATE_2400 : UBRRL= 160; UBRRH=1; break;
          case USART_BAUD_RATE_4800 : UBRRL= 207; UBRRH=0; break;
          case USART_BAUD_RATE_9600 : UBRRL= 103; UBRRH=0; break;
          case USART_BAUD_RATE_14400 : UBRRL= 68; UBRRH=0; break;
          case USART_BAUD_RATE_19200 : UBRRL= 51; UBRRH=0; break;
          case USART_BAUD_RATE_28800 : UBRRL= 34; UBRRH=0; break;
          case USART_BAUD_RATE_38400 : UBRRL= 25; UBRRH=0; break;
          case USART_BAUD_RATE_57600 : UBRRL= 16; UBRRH=0; break;
          case USART_BAUD_RATE_76800 : UBRRL= 12; UBRRH=0; break;

          } break;


  }

SET_BIT(reg_copy,7); // to access UCSRC

switch(Add_ptrPointerUSART->USART_mode)
  {
   case USART_MODE_SELECT_SYNCHRONOUS: SET_BIT(reg_copy,6); break;
   case USART_MODE_SELECT_ASYNCHRONOUS: CLR_BIT(reg_copy,6); break;
  }

switch(Add_ptrPointerUSART->Parity_Mode)
  {
   case USART_PARITY_MODE_DISABLE: CLR_BIT(reg_copy,5);  CLR_BIT(reg_copy,4); break;
   case USART_PARITY_MODE_EVEN: SET_BIT(reg_copy,5);  CLR_BIT(reg_copy,4); break;
   case USART_PARITY_MODE_ODD: SET_BIT(reg_copy,5);  SET_BIT(reg_copy,4); break;
  }

switch(Add_ptrPointerUSART->num_of_Stop_bits)
  {
   case USART_STOP_1_BIT: CLR_BIT(reg_copy,3); break;
   case USART_STOP_2_BIT: SET_BIT(reg_copy,3); break;

  }

switch(Add_ptrPointerUSART->data_size)
  {
   case USART_DATA_SIZE_5_BIT: CLR_BIT(UCSRB,2); CLR_BIT(reg_copy,2);  CLR_BIT(reg_copy,1); break;
   case USART_DATA_SIZE_6_BIT: CLR_BIT(UCSRB,2); CLR_BIT(reg_copy,2);  SET_BIT(reg_copy,1); break;
   case USART_DATA_SIZE_7_BIT: CLR_BIT(UCSRB,2); SET_BIT(reg_copy,2);  CLR_BIT(reg_copy,1); break;
   case USART_DATA_SIZE_8_BIT: CLR_BIT(UCSRB,2); SET_BIT(reg_copy,2);  SET_BIT(reg_copy,1); break;
   case USART_DATA_SIZE_9_BIT: SET_BIT(UCSRB,2); SET_BIT(reg_copy,2);  SET_BIT(reg_copy,1); break;

  }

switch(Add_ptrPointerUSART->Clock_Polarity)
  {
  case USART_CLK_POLARITY_1: CLR_BIT(reg_copy,0); break;
  case USART_CLK_POLARITY_2: SET_BIT(reg_copy,0); break;
  case USART_CLK_POLARITY_DISABLE: CLR_BIT(reg_copy,0); break;
  }

// put the value of reg_copy in UCSRA
UCSRA=reg_copy;

// enable RX
SET_BIT(UCSRB,4);
//enable TX
SET_BIT(UCSRB,3);

}

void UART_voidSendChar(u8 data)
{

// Wait until transmission reg emp

	while(GET_BIT(UCSRA,5)==0){}
    UDR_T=data;

}



u8 UART_u8GetChar(void)
{
  u8 Result;

	while(GET_BIT(UCSRA,7)==0){}



  Result=UDR_R;

 return Result;
}
