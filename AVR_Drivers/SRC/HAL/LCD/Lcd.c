/*
 * Lcd.c

 *
 *  Created on: Sep 9, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/HAL/Lcd/Lcd.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include"../../../SERVICES/std_types.h"
#include "util/delay.h"
void Lcd_vidEnablePulse(Lcd_tstrucCfg*Add_strucLcd){
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->EN_Pin,DIO_u8_HIGH);
	_delay_ms(2);
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->EN_Pin,DIO_u8_LOW);
}

//Send Command
void Lcd_vidSendCommand(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_CommandVal){
	//RS
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->RS_Pin,DIO_u8_LOW);
	// Send Command
	DIO_enuSetPortValue(Add_strucLcd->DataPortId,Copy_CommandVal);
	Lcd_vidEnablePulse(Add_strucLcd);
}

//Send Data
void Lcd_vidSendData(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_DataVal){
	//RS
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->RS_Pin,DIO_u8_HIGH);
	// Send Command
	DIO_enuSetPortValue(Add_strucLcd->DataPortId,Copy_DataVal);
	Lcd_vidEnablePulse(Add_strucLcd);
}
// Init
void Lcd_vidInit(Lcd_tstrucCfg*Add_strucLcd){
	///////////////////////////////////////////////////////////////////////////////////////////
	DIO_enuSetPinDirection(Add_strucLcd->CtrlPortId,Add_strucLcd->EN_Pin,DIO_u8_OUTPUT);//EN
	DIO_enuSetPinDirection(Add_strucLcd->CtrlPortId,Add_strucLcd->RS_Pin,DIO_u8_OUTPUT);//RS
	DIO_enuSetPinDirection(Add_strucLcd->CtrlPortId,Add_strucLcd->RW_Pin,DIO_u8_OUTPUT);//RW
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->RW_Pin,DIO_u8_LOW); // always write
	DIO_enuSetPortDirection(Add_strucLcd->DataPortId,DIO_u8_PORT_OUTPUT);//DataPort Direction
	///////////////////////////////////////////////////////////////////////////////////////////
	_delay_ms(30);
	//set
	Lcd_vidSendCommand(Add_strucLcd,0b00111000);
	_delay_ms(1);
	// Display On / Off
	Lcd_vidSendCommand(Add_strucLcd,0b00001100);
	_delay_ms(1);

	Lcd_vidSendCommand(Add_strucLcd,0b00000001);

}
/////////////////////////////////////
void Lcd_WriteString(Lcd_tstrucCfg*Add_strucLcd,u8*Add_u8LcdString){
	for(u8 StringCounter=0;Add_u8LcdString[StringCounter]!='\0';StringCounter++){
		Lcd_vidSendData(Add_strucLcd,Add_u8LcdString[StringCounter]);
	}
}

////////////////////////////////////////////////
void Lcd_WriteNumber(Lcd_tstrucCfg*Add_strucLcd,u16*Add_u8LcdNumber){
	if(*Add_u8LcdNumber<10)
		Lcd_vidSendData(Add_strucLcd,(*Add_u8LcdNumber)+48);

	//for operations
	else if(*Add_u8LcdNumber>=10)
	{
		u8 arrSaveDigitOfNum[16];
		u8 size=0;
		u32 value=*Add_u8LcdNumber;
		while(value!=0)
		{
			arrSaveDigitOfNum[size]=value % 10;
			value/=10;

			size++;
		}

		for(u8 counter=size-1;counter>=0;counter--)
		{

			Lcd_vidSendData(Add_strucLcd,(arrSaveDigitOfNum[counter])+48);
              if(counter==0)
            	  break;

		}


	}

}
/////////////////////////////////////////
void Lcd_gotoPosition(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_u8linePosition,u8 Copy_u8digitPosition)
{

switch(Copy_u8linePosition)
 {

case 0:Lcd_vidSendCommand(Add_strucLcd,LCD_LINE1+Copy_u8digitPosition); break;

case 1:Lcd_vidSendCommand(Add_strucLcd,LCD_LINE2+Copy_u8digitPosition); break;


 }

}
//////////////////////////////////////////////


