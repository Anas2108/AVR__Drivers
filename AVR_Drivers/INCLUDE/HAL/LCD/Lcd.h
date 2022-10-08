/*
 * Lcd.h
 *
 *  Created on: Sep 9, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_LCD_LCD_H_
#define INCLUDE_HAL_LCD_LCD_H_
#include "../../../SERVICES/std_types.h"
typedef struct {
	u8 DataPortId;
	u8 CtrlPortId;
	u8 RS_Pin;
	u8 RW_Pin;
	u8 EN_Pin;
}Lcd_tstrucCfg;
/////////////////////////////////////
//RS
#define LCD_SEND_COMMAND 0
#define LCD_SEND_DATA 1
//RW
#define LCD_WRITE_DATA 0
#define LCD_READ_DATA 1
//EN
#define LCD_ENABLE 1
#define LCD_DISABLE 0
//
#define LCD_LINE1 128
#define LCD_LINE2 128+0x40
////////////////////////////////////
void Lcd_vidEnablePulse(Lcd_tstrucCfg*Add_structLcd);
void Lcd_vidSendCommand(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_CommandVal);
void Lcd_vidSendData(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_DataVal);
void Lcd_vidInit(Lcd_tstrucCfg*Add_structLcd);
void Lcd_WriteString(Lcd_tstrucCfg*Add_strucLcd,u8*Add_u8LcdString);
void  Lcd_WriteNumber(Lcd_tstrucCfg*Add_strucLcd,u16*Add_u8LcdNumber);

void Lcd_gotoPosition(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_u8linePosition,u8 Copy_u8digitPosition);





#endif /* INCLUDE_HAL_LCD_LCD_H_ */
