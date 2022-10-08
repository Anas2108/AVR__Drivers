/*
 * Segment.c
 *
 *  Created on: Sep 6, 2022
 *      Author: ANOOS
 */
#include "../../../INCLUDE/HAL/SEGMENT/Segment.h"
#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "../../../INCLUDE/HAL/SEGMENT/Segment_prv.h"
#include "../../../SERVICES/bit_utilies.h"

void SEGMENT_voidSetSegmentDir(segment_str *Copy_segmentStrPointer){

DIO_enuSetPortDirection(Copy_segmentStrPointer->portId,DIO_u8_PORT_OUTPUT);


}

void SEGMENT_voidSetSegmentVal(segment_str *Add_segmentStrPointer,u8 Copy_segmentVal){

	if( Add_segmentStrPointer->segmentType == SEGMENT_COMMON_CATHOD)
	{
		DIO_enuSetPortValue(Add_segmentStrPointer->portId,Copy_segmentVal);

	}

	else if(Add_segmentStrPointer->segmentType == SEGMENT_COMMON_ANODE)

	{

		DIO_enuSetPortValue(Add_segmentStrPointer->portId,~(Copy_segmentVal));

	}


}
