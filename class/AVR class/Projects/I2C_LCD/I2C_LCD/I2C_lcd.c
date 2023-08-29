/*
 * I2C_lcd.c
 *
 * Created: 2023-08-29 오후 4:17:56
 *  Author: user
 */ 




#include "I2C_lcd.h"



void LCD_init() {
	I2C_init();
	
	_delay_ms(15);
	LCD_write_cmd(0x03);
	_delay_ms(4.1);
	LCD_write_cmd(0x03);
	_delay_ms(0.1);
	LCD_write_cmd(0x03);
	
	LCD_write_cmd(0x02);
	LCD_write_cmd(CMD_4BIT_MODE);
	LCD_write_cmd(CMD_DISPLAY_OFF);
	LCD_write_cmd(CMD_DISPLAY_CLEAR);
	LCD_write_cmd(CMD_ENTRY_MODE);
	LCD_write_cmd(CMD_DISPLAY_ON);
}
void LCD_4bit_data(uint8_t data) {
	
}
void LCD_enable_pin() {
	
}
void LCD_write_cmd(uint8_t cmd) {
	
}
void LCD_write_data(uint8_t a) {
	
}
void LCD_backLight_on() {
	
}
void LCD_goto_XY(uint8_t a, uint8_t b) {
	
}
void LCD_write_str(char *a) {
	
}
void LCD_write_str_XY(uint8_t a, uint8_t b, char *c) {
	
}