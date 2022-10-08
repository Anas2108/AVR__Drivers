/*
 * Led.c
 *
 *  Created on: Sep 4, 2022
 *      Author: ANOOS
 */
#include "../../../INCLUDE/HAL/LED/Led.h"
#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "../../../INCLUDE/HAL/LED/Led_prv.h"
#include "../../../SERVICES/bit_utilies.h"

void Led_voidSetLedDir(Led_str * Add_ledStrPointer){
 DIO_enuSetPinDirection(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId,DIO_u8_OUTPUT);

}


void Led_voidTurnOn(Led_str *Add_ledStrPointer){

	if (Add_ledStrPointer->Active_State == LED_u8_Active_High)

	{

		DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_High_H);
				Add_ledStrPointer->Curent_State=LED_u8_Active_High_H;

	}


	else if(Add_ledStrPointer->Active_State == LED_u8_Active_Low)
	{

		DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_Low_H);
						Add_ledStrPointer->Curent_State=LED_u8_Active_Low_H;


	}

}



void Led_voidTurnOff(Led_str *Add_ledStrPointer){

	if (Add_ledStrPointer->Active_State == LED_u8_Active_High)

	{

		DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_High_L);
				Add_ledStrPointer->Curent_State=LED_u8_Active_High_L ;

	}


	else if(Add_ledStrPointer->Active_State == LED_u8_Active_Low)
	{

		DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_Low_L);
						Add_ledStrPointer->Curent_State=LED_u8_Active_Low_L;


	}

}


void Led_voidToggle(Led_str *Add_ledStrPointer){


	if (Add_ledStrPointer->Active_State == LED_u8_Active_High)

	{

		if(Add_ledStrPointer->Curent_State==LED_u8_Active_High_L)


		{

			DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_High_H);


									Add_ledStrPointer->Curent_State=LED_u8_Active_High_H;


		}



		else if(Add_ledStrPointer->Curent_State==LED_u8_Active_High_H)


				{

					DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_High_L);


											Add_ledStrPointer->Curent_State=LED_u8_Active_High_L;


				}





	}

	/// FOR ACTIVE LOW
	if (Add_ledStrPointer->Active_State == LED_u8_Active_Low)

		{

			if(Add_ledStrPointer->Curent_State==LED_u8_Active_Low_L)


			{

				DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_Low_H);


										Add_ledStrPointer->Curent_State=LED_u8_Active_Low_H;


			}



			else if(Add_ledStrPointer->Curent_State==LED_u8_Active_Low_H)


					{

						DIO_enuSetPinValue(Add_ledStrPointer -> portId ,Add_ledStrPointer-> pinId, LED_u8_Active_Low_L);


												Add_ledStrPointer->Curent_State=LED_u8_Active_Low_L;


					}





		}












}








