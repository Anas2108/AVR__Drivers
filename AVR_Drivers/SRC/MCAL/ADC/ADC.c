/*
 * ADC.c
 *
 *  Created on: Sep 24, 2022
 *      Author: ANOOS
 */
#include "../../../INCLUDE/MCAL/ADC/ADC.h"
#include "../../../INCLUDE/MCAL/ADC/ADC_prv.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"
#include "../../../SERVICES/bit_utilies.h"

void ADC_voidInit(ADC_str * Add_strPointerADC)
{

switch( Add_strPointerADC->pin_Id)
  {
case ADC_REF_SELECTION_AREF: CLR_BIT(ADMUX,7); CLR_BIT(ADMUX,6); break;
case ADC_REF_SELECTION_AVCC: CLR_BIT(ADMUX,7); SET_BIT(ADMUX,6); break;// Referance Voltage as AVCC with external capacitor
case ADC_REF_SELECTION_VREF: SET_BIT(ADMUX,7); SET_BIT(ADMUX,6); break;
  }

switch( Add_strPointerADC->left_adjust)
  {
case ADC_ADLAR_DISABLE: CLR_BIT(ADMUX,5); break;
case ADC_ADLAR_ENABLE: SET_BIT(ADMUX,5); break;

  }

switch( Add_strPointerADC->devision_factor)
  {
case ADC_DEVISION_FACTOR_2: CLR_BIT(ADCSRA,2);CLR_BIT(ADCSRA,1);CLR_BIT(ADCSRA,0);break;
case ADC_DEVISION_FACTOR_4: CLR_BIT(ADCSRA,2);SET_BIT(ADCSRA,1);CLR_BIT(ADCSRA,0);break;
case ADC_DEVISION_FACTOR_8: CLR_BIT(ADCSRA,2);SET_BIT(ADCSRA,1);SET_BIT(ADCSRA,0);break;
case ADC_DEVISION_FACTOR_16: SET_BIT(ADCSRA,2);CLR_BIT(ADCSRA,1);CLR_BIT(ADCSRA,0);break;
case ADC_DEVISION_FACTOR_32: SET_BIT(ADCSRA,2);CLR_BIT(ADCSRA,1);SET_BIT(ADCSRA,0);break;
case ADC_DEVISION_FACTOR_64: SET_BIT(ADCSRA,2);SET_BIT(ADCSRA,1);CLR_BIT(ADCSRA,0);break;
case ADC_DEVISION_FACTOR_128: SET_BIT(ADCSRA,2);SET_BIT(ADCSRA,1);SET_BIT(ADCSRA,0);break;

  }


SET_BIT(ADCSRA,7); //enable ADC



}

void ADC_voidRead(ADC_str * Add_strPointerADC,u16 *Add_u16ADCvalue)
{
	switch( Add_strPointerADC->pin_Id)
	  {
	case ADC_0: ADMUX|=ADC_0; break;
	case ADC_1: ADMUX|=ADC_1; break;
	case ADC_2: ADMUX|=ADC_2; break;
	case ADC_3: ADMUX|=ADC_3; break;
	case ADC_4: ADMUX|=ADC_4; break;
	case ADC_5: ADMUX|=ADC_5; break;
	case ADC_6: ADMUX|=ADC_6; break;

	  }

//to start single conversion

	SET_BIT(ADCSRA,6);


	while(GET_BIT(ADCSRA,6)==1 )
	{


	}


		*Add_u16ADCvalue=ADC;


}
/////////
void ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA,7); //Disable ADC
}




