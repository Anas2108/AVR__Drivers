/*
 * SPI_prv.h
 *
 *  Created on: Oct 22, 2022
 *      Author: ANOOS
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRV_H_
#define INCLUDE_MCAL_SPI_SPI_PRV_H_

#define SPCR *((volatile u8*) 0x2C)   //SPI Control Register
#define SPSR *((volatile u8*) 0x2C)  //SPI Status Register
#define SPDR *((volatile u8*) 0x2B)  //Data reg

#endif /* INCLUDE_MCAL_SPI_SPI_PRV_H_ */
