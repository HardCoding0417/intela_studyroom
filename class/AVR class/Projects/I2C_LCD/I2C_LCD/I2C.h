/*
 * I2C.h
 *
 * Created: 2023-08-29 오후 3:37:10
 *  Author: user
 */ 


#ifndef I2C_H_
#define I2C_H_



#include <avr/io.h>


#define I2C_DDR DDRD
#define I2C_SCL PORTD0
#define I2C_SDA PORTD1



void I2C_init();

void I2C_start();
void I2C_stop();

void I2C_TXData(uint8_t);

void I2C_TXByte(uint8_t, uint8_t);



#endif /* I2C_H_ */