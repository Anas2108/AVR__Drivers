/*
 * TIMER.c
 *
 *  Created on: Oct 2, 2022
 *      Author: ANOOS
 */

#include "../../../INCLUDE/MCAL/TIMER/TIMER.h"
#include "../../../INCLUDE/MCAL/TIMER/TIMER_prv.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"
#include "../../../SERVICES/bit_utilies.h"

void TIMER_voidInit(str_timer *Add_ptrTimer )
{

	switch(Add_ptrTimer->channel){
	case TIMER_CHANNEL_A:

	switch (Add_ptrTimer->WGM)
	{
	case TIMER_NORMAL_MODE: CLR_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

	  switch(Add_ptrTimer->COM)
	  {
	  case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6);  SET_BIT(TIMSK,2); break;
	  case TIMER_COM_TOGGLE:  CLR_BIT(TCCR1A,7);  SET_BIT(TCCR1A,6);   break;
	  case TIMER_COM_CLEAR:  SET_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6);   break;
	  case TIMER_COM_SET:  SET_BIT(TCCR1A,7);  SET_BIT(TCCR1A,6);   break;

	  }

	break;
	case TIMER_CTC_MODE: CLR_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

	switch(Add_ptrTimer->COM)
		  {
		  case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6);  SET_BIT(TIMSK,4); break;
		  case TIMER_COM_TOGGLE:  CLR_BIT(TCCR1A,7);  SET_BIT(TCCR1A,6);   break;
		  case TIMER_COM_CLEAR:  SET_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6);   break;
		  case TIMER_COM_SET:  SET_BIT(TCCR1A,7);  SET_BIT(TCCR1A,6);   break;

		  }

	break;
	case TIMER_FAST_PWM_ICR_MODE: SET_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

	switch(Add_ptrTimer->COM)
			  {
			  case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6); break; //pwm  by software
			  case TIMER_NON_INVERTING:  SET_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6);   break;
			  case TIMER_INVERTING:  SET_BIT(TCCR1A,7);  SET_BIT(TCCR1A,6);   break;

			  }

	break;
	case TIMER_PWM_PHASE_CORRECT_ICR_MODE: SET_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

	switch(Add_ptrTimer->COM)
				  {
	               case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6); break; //pwm  by software
				  case TIMER_NON_INVERTING:  SET_BIT(TCCR1A,7);  CLR_BIT(TCCR1A,6);   break;
				  case TIMER_INVERTING:  SET_BIT(TCCR1A,7);  SET_BIT(TCCR1A,6);   break;

				  }

	break;

	}

	break;

	case TIMER_CHANNEL_B:

		switch (Add_ptrTimer->WGM)
		{
		case TIMER_NORMAL_MODE: CLR_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

		  switch(Add_ptrTimer->COM)
		  {
		  case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4); SET_BIT(TIMSK,2); break;
		  case TIMER_COM_TOGGLE:  CLR_BIT(TCCR1A,5);  SET_BIT(TCCR1A,4);   break;
		  case TIMER_COM_CLEAR:  SET_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4);   break;
		  case TIMER_COM_SET:  SET_BIT(TCCR1A,5);  SET_BIT(TCCR1A,4);   break;

		  }

		break;
		case TIMER_CTC_MODE: CLR_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

		switch(Add_ptrTimer->COM)
			  {
			  case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4);   SET_BIT(TIMSK,3); break;
			  case TIMER_COM_TOGGLE:  CLR_BIT(TCCR1A,5);  SET_BIT(TCCR1A,4);   break;
			  case TIMER_COM_CLEAR:  SET_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4);   break;
			  case TIMER_COM_SET:  SET_BIT(TCCR1A,5);  SET_BIT(TCCR1A,4);   break;

			  }

		break;
		case TIMER_FAST_PWM_ICR_MODE: SET_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

		switch(Add_ptrTimer->COM)
				  {
				  case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4); break; //pwm  by software
				  case TIMER_NON_INVERTING:  SET_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4);   break;
				  case TIMER_INVERTING:  SET_BIT(TCCR1A,5);  SET_BIT(TCCR1A,4);   break;

				  }

		break;
		case TIMER_PWM_PHASE_CORRECT_ICR_MODE: SET_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0);

		switch(Add_ptrTimer->COM)
					  {
		               case TIMER_COM_NORMAL_OPERATION: CLR_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4); break; //pwm  by software
					  case TIMER_NON_INVERTING:  SET_BIT(TCCR1A,5);  CLR_BIT(TCCR1A,4);   break;
					  case TIMER_INVERTING:  SET_BIT(TCCR1A,5);  SET_BIT(TCCR1A,4);   break;

					  }

		break;

		}

		break;




}







	switch (Add_ptrTimer->prescale)
	{
	case TIMER_NO_CLK : CLR_BIT(TCCR1B,2); CLR_BIT(TCCR1B,1); CLR_BIT(TCCR1B,0); break;
	case TIMER_CLK_DEVIDED_BY_1 : CLR_BIT(TCCR1B,2); CLR_BIT(TCCR1B,1); SET_BIT(TCCR1B,0); break;
	case TIMER_CLK_DEVIDED_BY_8 : CLR_BIT(TCCR1B,2); SET_BIT(TCCR1B,1); CLR_BIT(TCCR1B,0); break;
	case TIMER_CLK_DEVIDED_BY_64 : CLR_BIT(TCCR1B,2); SET_BIT(TCCR1B,1); SET_BIT(TCCR1B,0); break;
	case TIMER_CLK_DEVIDED_BY_256 : SET_BIT(TCCR1B,2); CLR_BIT(TCCR1B,1); CLR_BIT(TCCR1B,0); break;
	case TIMER_CLK_DEVIDED_BY_1024 : SET_BIT(TCCR1B,2); CLR_BIT(TCCR1B,1); SET_BIT(TCCR1B,0); break;

	}

}





