/*
 * Switch.c
 *
 *  Created on: Sep 6, 2022
 *      Author: ANOOS
 */

#include "../../../INCLUDE/HAL/SWITCH/Switch.h"
#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "../../../INCLUDE/HAL/SWITCH/Switch_prv.h"
#include "../../../SERVICES/bit_utilies.h"


void SWITCH_voidSetSwitchDir(Switch_str *Add_strPtrswitch)
{

DIO_enuSetPinDirection(Add_strPtrswitch->portId,Add_strPtrswitch->pinId,DIO_u8_INPUT);

DIO_enuSetPinValue(Add_strPtrswitch->portId,Add_strPtrswitch->pinId,DIO_u8_HIGH); //TO BECOME PULLUP

}



u8 SWITCH_voidSetSwitchRead(Switch_str *Add_strPtrswitch){

return DIO_u8GetPinValue(Add_strPtrswitch->portId,Add_strPtrswitch->pinId);
}
