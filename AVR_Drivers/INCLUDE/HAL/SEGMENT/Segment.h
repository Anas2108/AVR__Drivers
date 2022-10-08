/*
 * Segment.h
 *
 *  Created on: Sep 6, 2022
 *      Author: ANOOS
 */
#include "../../../SERVICES/STD_TYPES.h"
#ifndef INCLUDE_HAL_SEGMENT_SEGMENT_H_
#define INCLUDE_HAL_SEGMENT_SEGMENT_H_


//TYPE OF 7-SEGMENT
#define SEGMENT_COMMON_CATHOD 1
#define SEGMENT_COMMON_ANODE 0

//STRUCT OF THE 7-SEGMENT

typedef struct {

	u8 portId;
	u8 segmentType;


}segment_str;


void SEGMENT_voidSetSegmentDir(segment_str *Add_segmentStrPointer);

void SEGMENT_voidSetSegmentVal(segment_str *Add_segmentStrPointer,u8 Copy_segmentVal);



#endif /* INCLUDE_HAL_SEGMENT_SEGMENT_H_ */
