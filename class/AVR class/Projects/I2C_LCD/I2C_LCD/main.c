/*
 * I2C_LCD.c
 *
 * Created: 2023-08-29 오후 3:36:17
 * Author : Choi Myeongsu
 */ 




#include <stdio.h>

#include "I2C_lcd.h"



int main(void)
{
	uint16_t cnt = 0;
	char buf[30];
	
	LCD_init();
	LCD_backLight_on();
	LCD_write_str_XY(0, 0, "Hello ATmega128A");
	
    while (1) 
    {
		sprintf(buf, "count: %-5d", cnt++);
		LCD_write_str_XY(1, 0, buf);
    }
}

