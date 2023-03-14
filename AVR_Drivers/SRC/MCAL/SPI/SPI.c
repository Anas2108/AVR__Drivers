/*
 * SPI.c
 *
 *  Created on: Oct 22, 2022
 *      Author: ANOOS
 */


#include "../../../INCLUDE/MCAL/SPI/SPI.h"
#include "../../../INCLUDE/MCAL/SPI/SPI_prv.h"
#include "../../../SERVICES/bit_utilies.h"
#include "../../../INCLUDE/MCAL/DIO/Dio_prv.h"

void SPI_voidMasterInit (MSPI_str *Add_ptrMSPI)
{

switch(Add_ptrMSPI->data_order)
 {
  case SPI_DATA_ORDER_LSB_FIRST : SET_BIT(SPCR,5); break;

  case SPI_DATA_ORDER_MSB_FIRST : CLR_BIT(SPCR,5); break;

 }

switch(Add_ptrMSPI->clock_polarity)

 {
 case SPI_CLOCK_POLARITY_MODE_1 : SET_BIT(SPCR,3); break;

 case SPI_CLOCK_POLARITY_MODE_2 : CLR_BIT(SPCR,3); break;

 }

switch (Add_ptrMSPI->clock_phase)

 {
case SPI_CLOCK_PHASE_MODE_1: CLR_BIT(SPCR,2); break;
case SPI_CLOCK_PHASE_MODE_2: SET_BIT(SPCR,2); break;
 }

switch(Add_ptrMSPI->clock_scale)
 {
case SPI_CLK_DEVIDED_BY_2: SET_BIT(SPSR,0); CLR_BIT(SPCR,1); CLR_BIT(SPCR,0); break;
case SPI_CLK_DEVIDED_BY_4: CLR_BIT(SPSR,0); CLR_BIT(SPCR,1); CLR_BIT(SPCR,0); break;
case SPI_CLK_DEVIDED_BY_8: SET_BIT(SPSR,0); CLR_BIT(SPCR,1); SET_BIT(SPCR,0); break;
case SPI_CLK_DEVIDED_BY_16: CLR_BIT(SPSR,0); CLR_BIT(SPCR,1); SET_BIT(SPCR,0); break;
case SPI_CLK_DEVIDED_BY_32: SET_BIT(SPSR,0); SET_BIT(SPCR,1); CLR_BIT(SPCR,0); break;
case SPI_CLK_DEVIDED_BY_64: CLR_BIT(SPSR,0); SET_BIT(SPCR,1); CLR_BIT(SPCR,0); break;
case SPI_CLK_DEVIDED_BY_128: CLR_BIT(SPSR,0); SET_BIT(SPCR,1); SET_BIT(SPCR,0); break;
 }

SET_BIT(SPCR,4); //TO SET MASTER MODE
SET_BIT(SPCR,6); // TO ENABLE SPI

}


void SPI_voidSlaveInit (MSPI_str *Add_ptrSSPI)
{

switch(Add_ptrSSPI->data_order)
 {
  case SPI_DATA_ORDER_LSB_FIRST : SET_BIT(SPCR,5); break;

  case SPI_DATA_ORDER_MSB_FIRST : CLR_BIT(SPCR,5); break;

 }

switch(Add_ptrSSPI->clock_polarity)

 {
 case SPI_CLOCK_POLARITY_MODE_1 : SET_BIT(SPCR,3); break;

 case SPI_CLOCK_POLARITY_MODE_2 : CLR_BIT(SPCR,3); break;

 }

switch (Add_ptrSSPI->clock_phase)

 {
case SPI_CLOCK_PHASE_MODE_1: CLR_BIT(SPCR,2); break;
case SPI_CLOCK_PHASE_MODE_2: SET_BIT(SPCR,2); break;
 }



CLR_BIT(SPCR,4); //TO SET SLAVE MODE
SET_BIT(SPCR,6); // TO ENABLE SPI

}


u8 SPI_u8DataTransfer (u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;

	while(GET_BIT(SPSR,7)==0);

	return SPDR;


}
