/*
 * I2C_LCD.c
 *
 *  Created on: Sep 14, 2023
 *      Author: user
 */




#include "lcd.h"



// Initialize LCD as the datasheet suggests
void LCD_init() {
    HAL_Delay(15);
    LCD_send_cmd(0x30);
    HAL_Delay(5);
    LCD_send_cmd(0x30);
    HAL_Delay(1);
    LCD_send_cmd(0x30);
    HAL_Delay(10);
    LCD_send_cmd(0x20);
    HAL_Delay(10);

    LCD_send_cmd(0x28);
    HAL_Delay(10);
    LCD_send_cmd(0x08);
    HAL_Delay(10);
    LCD_send_cmd(0x01);
    HAL_Delay(10);
    LCD_send_cmd(0x0c);
    HAL_Delay(10);
    LCD_send_cmd(0x06);
}

// Clear LCD
void LCD_clear() {
    HAL_Delay(10);
    LCD_send_cmd(0x08);
    for (int8_t i = 0; i < 32; i++) {
        LCD_send_data('\0');
    }
}
// Locate cursor on LCD
// row: row 0 ~ 1 / col: column 0 ~ 15
void LCD_put_cursor(uint8_t row, uint8_t col) {
    if (row == 0) {
        col |= 0x80;
    }
    else if (row == 1) {
        col |= 0xc0;
    }

    HAL_Delay(10);
    LCD_send_cmd(col);
}

// Send command to LCD
void LCD_send_cmd(uint8_t cmd) {
    uint8_t cmd_t[4];
    uint8_t cmd_h, cmd_l;

    cmd_h = cmd & 0xf0;
    cmd_l = cmd << 4 & 0xf0;

    cmd_t[0] = cmd_h | 0x0c;
    cmd_t[1] = cmd_h | 0x08;
    cmd_t[2] = cmd_l | 0x0c;
    cmd_t[3] = cmd_l | 0x08;

    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDRESS, cmd_t, sizeof(cmd_t), 4);
}
// Send byte size data to LCD
void LCD_send_data(char data) {
    uint8_t data_t[4];
    uint8_t data_h, data_l;

    data_h = data & 0xf0;
    data_l = data << 4 & 0xf0;

    data_t[0] = data_h | 0x0d;
    data_t[1] = data_h | 0x09;
    data_t[2] = data_l | 0x0d;
    data_t[3] = data_l | 0x09;

    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDRESS, data_t, sizeof(data_t), 4);
}
// Send string to LCD
void LCD_send_str(char *str) {
    while (*str) {
        LCD_send_data(*str++);
    }
}
