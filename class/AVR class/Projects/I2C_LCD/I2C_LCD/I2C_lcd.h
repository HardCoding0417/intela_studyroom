/*
 * I2C_lcd.h
 *
 * Created: 2023-08-29 오후 4:17:49
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_



#define F_CPU 16000000UL
#include <util/delay.h>

#include "I2C.h"


#define LCD_RS 0
#define LCD_RW 1
#define LCD_E 2
#define LCD_BACKLIGHT 3

#define LCD_ADDR (0x27 << 1) // << 1: stay write mode(?)

#define CMD_DISPLAY_CLEAR 0x01
#define CMD_DISPLAY_ON 0x0c
#define CMD_DISPLAY_OFF 0x08
#define CMD_4BIT_MODE 0x28
#define CMD_ENTRY_MODE 0x06



void LCD_init();
void LCD_4bit_data(uint8_t);
void LCD_enable_pin();
void LCD_write_cmd(uint8_t);
void LCD_write_data(uint8_t);
void LCD_backLight_on();
void LCD_goto_XY(uint8_t, uint8_t);
void LCD_write_str(char *);
void LCD_write_str_XY(uint8_t, uint8_t, char *);



#endif /* LCD_H_ */