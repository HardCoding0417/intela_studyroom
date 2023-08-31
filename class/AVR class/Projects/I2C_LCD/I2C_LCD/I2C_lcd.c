/*
 * I2C_lcd.c
 *
 * Created: 2023-08-29 오후 4:17:56
 *  Author: user
 */ 




#include "I2C_lcd.h"



uint8_t LCD_data;


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
	LCD_data = (LCD_data & 0x0f) | (data & 0xf0);
	LCD_enable_pin();
	LCD_data = (LCD_data & 0x0f) | (data & 0x0f) << 4;
	LCD_enable_pin();
}
void LCD_enable_pin() {
	LCD_data &= ~(1 << LCD_E);
	I2C_TXByte(LCD_ADDR, LCD_data);
	
	LCD_data |= 1 << LCD_E;
	I2C_TXByte(LCD_ADDR, LCD_data);
	
	LCD_data &= ~(1 << LCD_E);
	I2C_TXByte(LCD_ADDR, LCD_data);
	
	_delay_ms(20);
}
void LCD_write_cmd(uint8_t cmd) {
	LCD_data &= ~(1 << LCD_RS);
	LCD_data &= ~(1 << LCD_RW);
	LCD_4bit_data(cmd);
}
void LCD_write_data(uint8_t ch) {
	LCD_data |= 1 << LCD_RS;
	LCD_data &= ~(1 << LCD_RW);
	LCD_4bit_data(ch);
}
void LCD_backLight_on() {
	LCD_data |= 1 << LCD_BACKLIGHT;
	I2C_TXByte(LCD_ADDR, LCD_data);
}
void LCD_goto_XY(uint8_t row, uint8_t col) {
	uint8_t addr = 0x40 * row + col;
	uint8_t cmd = 0x80 + addr;
	LCD_write_cmd(cmd);
}
void LCD_write_str(char *str) {
	for (uint8_t i = 0; str[i]; i++) {
		LCD_write_data(str[i]);
	}
}
void LCD_write_str_XY(uint8_t row, uint8_t col, char *str) {
	LCD_goto_XY(row, col);
	LCD_write_str(str);
}