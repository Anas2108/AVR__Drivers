/*
 * SPI.h
 *
 *  Created on: Oct 22, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_SPI_SPI_H_
#define INCLUDE_MCAL_SPI_SPI_H_

#include "../../../SERVICES/STD_TYPES.h"


/*Data Order*/

#define SPI_DATA_ORDER_LSB_FIRST 0 // to start transmission from the LSB
#define SPI_DATA_ORDER_MSB_FIRST 1 // to start transmission from the MSB

/*Clock Polarity*/

#define SPI_CLOCK_POLARITY_MODE_1 0 // first edge falling and second edge rising
#define SPI_CLOCK_POLARITY_MODE_2 1 // first edge rising and second edge falling

/*Clock Phase*/

#define SPI_CLOCK_PHASE_MODE_1 0 // Leading Edge >>Sample (Read)   Trailing Edge>>Set(write)
#define SPI_CLOCK_PHASE_MODE_2 1 // Leading Edge >>  Set(write)  Trailing Edge>>Sample (Read)

/*Clock scale*/


#define SPI_CLK_DEVIDED_BY_2 0
#define SPI_CLK_DEVIDED_BY_4 1
#define SPI_CLK_DEVIDED_BY_8 2
#define SPI_CLK_DEVIDED_BY_16 3
#define SPI_CLK_DEVIDED_BY_32 4
#define SPI_CLK_DEVIDED_BY_64 5
#define SPI_CLK_DEVIDED_BY_128 6

/*master struct*/
typedef struct {

	u8 data_order;
	u8 clock_polarity;
	u8 clock_phase;
	u8 clock_scale;

} MSPI_str;

/*Slave struct*/
typedef struct {

	u8 data_order;
	u8 clock_polarity;
	u8 clock_phase;


} SSPI_str;


void SPI_voidMasterInit (MSPI_str *Add_ptrMSPI);
void SPI_voidSlaveInit (MSPI_str *Add_ptrSSPI);
u8 SPI_u8DataTransfer (u8 Copy_u8Data);

#endif /* INCLUDE_MCAL_SPI_SPI_H_ */
