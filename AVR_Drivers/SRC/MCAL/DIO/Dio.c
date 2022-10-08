#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"
#include "../../../SERVICES/bit_utilies.h"







// body of the function that use to put high or low on the pin



Dio_tenuErrorStatus DIO_enuSetPinValue (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal){
// check
	Dio_tenuErrorStatus LOC_enErrorStatus =Dio_enOk;
	if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)){

		if(Copy_u8PinVal==DIO_u8_HIGH){
			switch (Copy_u8PortId){

			case DIO_u8_PORTA : SET_BIT(PORTA_Register,Copy_u8PinId); break;
			case DIO_u8_PORTB : SET_BIT(PORTB_Register,Copy_u8PinId); break;
			case DIO_u8_PORTC : SET_BIT(PORTC_Register,Copy_u8PinId); break;
			case DIO_u8_PORTD : SET_BIT(PORTD_Register,Copy_u8PinId); break;
			default:/*wrong id */ break;
			}

			}

		else if(Copy_u8PinVal==DIO_u8_LOW){

			switch (Copy_u8PortId){

				case DIO_u8_PORTA : CLR_BIT(PORTA_Register,Copy_u8PinId); break;
				case DIO_u8_PORTB : CLR_BIT(PORTB_Register,Copy_u8PinId);break;
				case DIO_u8_PORTC : CLR_BIT(PORTC_Register,Copy_u8PinId);break;
				case DIO_u8_PORTD : CLR_BIT(PORTD_Register,Copy_u8PinId); break;
				default:/*wrong id */ break;
						}
		   }


    }

	else{
		 LOC_enErrorStatus =Dio_enInvalidInput;

	}

	return LOC_enErrorStatus;

}

////////////////////////////////DDR function//////////////////////////////////////////////

 Dio_tenuErrorStatus DIO_enuSetPinDirection (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir){

	 // check
	 	Dio_tenuErrorStatus LOC_enErrorStatus =Dio_enOk;
	 	if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)){

	 		if(Copy_u8PinDir==DIO_u8_OUTPUT){
	 			switch (Copy_u8PortId){

	 			case DIO_u8_PORTA : SET_BIT(DDRA_Register,Copy_u8PinId); break;
	 			case DIO_u8_PORTB : SET_BIT(DDRB_Register,Copy_u8PinId); break;
	 			case DIO_u8_PORTC : SET_BIT(DDRC_Register,Copy_u8PinId); break;
	 			case DIO_u8_PORTD : SET_BIT(DDRD_Register,Copy_u8PinId); break;
	 			default:/*wrong id */ break;
	 			}


	 			}

	 		else if(Copy_u8PinDir==DIO_u8_INPUT){

	 			switch (Copy_u8PortId){

	 		  case DIO_u8_PORTA : CLR_BIT(DDRA_Register,Copy_u8PinId); break;
	 		  case DIO_u8_PORTB : CLR_BIT(DDRB_Register,Copy_u8PinId);break;
	 		  case DIO_u8_PORTC : CLR_BIT(DDRC_Register,Copy_u8PinId);break;
	 		  case DIO_u8_PORTD : CLR_BIT(DDRD_Register,Copy_u8PinId); break;
	 		 default:/*wrong id */ break;
	 						}
	 		   }


	     }

	 	else{
	 		 LOC_enErrorStatus =Dio_enInvalidInput;

	 	}

	 	return LOC_enErrorStatus;

 }

///////////////////////////////get pin value >> PIN REG /////////////////////////////////////////

 u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId){

	 u8 LOC_u8ResultLocal;
	 if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)){

		 switch (Copy_u8PortId)
		 {
		 case DIO_u8_PORTA: LOC_u8ResultLocal=GET_BIT(PINA_Register,Copy_u8PinId) ; break;
		 case DIO_u8_PORTB: LOC_u8ResultLocal=GET_BIT(PINB_Register,Copy_u8PinId) ; break;
		 case DIO_u8_PORTC: LOC_u8ResultLocal=GET_BIT(PINC_Register,Copy_u8PinId) ; break;
		 case DIO_u8_PORTD: LOC_u8ResultLocal=GET_BIT(PIND_Register,Copy_u8PinId) ; break;
		 default:/*wrong id */ break;

		 }

	 }
	 else
		 LOC_u8ResultLocal=0xff;
return
		 LOC_u8ResultLocal;

 }

//////////////////////////////////////////port set whole output or whole input////////////////////////
 Dio_tenuErrorStatus DIO_enuSetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDir){

	 Dio_tenuErrorStatus LOC_enErrorStatus =Dio_enOk;
	 	 	if( Copy_u8PortId <= DIO_u8_PORTD ){


	 	 			 			switch (Copy_u8PortId){

	 	 			 			case DIO_u8_PORTA : DDRA_Register=Copy_u8PortDir; break;

	 	 			 			case DIO_u8_PORTB : DDRB_Register=Copy_u8PortDir; break;

	 	 			 			case DIO_u8_PORTC : DDRC_Register=Copy_u8PortDir; break;

	 	 			 			case DIO_u8_PORTD : DDRD_Register=Copy_u8PortDir; break;
	 	 			 			default:/*wrong id */ break;
	 	 			 			}


	 	 			     }
	 	 	else
	 	 		LOC_enErrorStatus =Dio_enInvalidInput;

	 	 	return  LOC_enErrorStatus;
	 	 	}

	 ///////////////////////////////////play with output 5v or 0//////////////

 Dio_tenuErrorStatus DIO_enuSetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortVal){  //for output

	 Dio_tenuErrorStatus LOC_enErrorStatus =Dio_enOk;
	 	 	if( Copy_u8PortId <= DIO_u8_PORTD ){


	 	 			 			switch (Copy_u8PortId){

	 	 			 			case DIO_u8_PORTA : PORTA_Register=Copy_u8PortVal; break;

	 	 			 			case DIO_u8_PORTB : PORTB_Register=Copy_u8PortVal; break;

	 	 			 			case DIO_u8_PORTC : PORTC_Register=Copy_u8PortVal; break;

	 	 			 			case DIO_u8_PORTD : PORTD_Register=Copy_u8PortVal; break;

	 	 			 			default:/*wrong id */ break;
	 	 			 			}


	 	 			     }
	 	 	else
	 	 	 LOC_enErrorStatus =Dio_enInvalidInput;

	 	 	return  LOC_enErrorStatus;
	 	 	}

