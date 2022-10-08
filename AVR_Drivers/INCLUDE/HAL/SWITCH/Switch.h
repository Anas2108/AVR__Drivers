/*
 * Switch.h
 *
 *  Created on: Sep 6, 2022
 *      Author: ANOOS
 */
#include "../../../SERVICES/STD_TYPES.h"


#ifndef INCLUDE_HAL_SWITCH_SWITCH_H_
#define INCLUDE_HAL_SWITCH_SWITCH_H_

#define SWITCH_READ_HIGH 0
#define SWITCH_READ_LOW 1


typedef struct {

	u8 portId;
	u8 pinId;

}Switch_str;



void SWITCH_voidSetSwitchDir(Switch_str *Add_strPtrswitch);


u8 SWITCH_voidSetSwitchRead(Switch_str *Add_strPtrswitch);




#endif /* INCLUDE_HAL_SWITCH_SWITCH_H_ */
