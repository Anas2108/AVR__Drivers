/*
 * ADC.h
 *
 *  Created on: Sep 24, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_ADC_ADC_H_
#define INCLUDE_MCAL_ADC_ADC_H_

#include "../../../SERVICES/STD_TYPES.h"
/*ADMUX REF selection */

#define ADC_REF_SELECTION_AREF 0
#define ADC_REF_SELECTION_AVCC 1
#define ADC_REF_SELECTION_VREF 2

/* ADMUX ADC left adjust result */
#define ADC_ADLAR_DISABLE 0
#define ADC_ADLAR_ENABLE 1

/*ADMUX Analog channel */
#define ADC_0 0
#define ADC_1 1
#define ADC_2 2
#define ADC_3 3
#define ADC_4 4
#define ADC_5 5
#define ADC_6 6
#define ADC_7 7

/*ADCSRA prescalling  */
#define ADC_DEVISION_FACTOR_2 0
#define ADC_DEVISION_FACTOR_4 1
#define ADC_DEVISION_FACTOR_8 2
#define ADC_DEVISION_FACTOR_16 3
#define ADC_DEVISION_FACTOR_32 4
#define ADC_DEVISION_FACTOR_64 5
#define ADC_DEVISION_FACTOR_128 6

/*SIFOR auto trigger source selections */
# define ADC_FREE_RUNING_MODE 0
# define ADC_EXTERNAL_INTERRUPT_REQUEST 1
# define ADC_ANALOG_COMPRATOR 2

/*the name of bits of all reg */

/////////////////////////////////////////////////////////////////////////////

typedef struct {

	u8 pin_Id;
	u8 ref_select;
	u8 left_adjust;
	u8 devision_factor;

}
ADC_str;


void ADC_voidInit(ADC_str * Add_strPointerADC);

void ADC_voidRead(ADC_str * Add_strPointerADC,u16 *Add_u16ADCvalue);

void ADC_voidDisable(void);


#endif /* INCLUDE_MCAL_ADC_ADC_H_ */
