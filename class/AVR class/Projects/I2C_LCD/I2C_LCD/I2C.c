/*
 * I2C.c
 *
 * Created: 2023-08-29 오후 3:37:02
 *  Author: user
 */ 




#include "I2C.h"



void I2C_init() {
	I2C_DDR |= 0x1 << I2C_SCL | 0x1 << I2C_SDA;
	TWBR = 72; // 100kHz SCL frequency
	
	TWCR |= 1 << TWEN;
}

void I2C_start() {
	TWCR |= 1 << TWINT | 1 << TWSTA;
	while (!(TWCR & 1 << TWINT)) {
		/* EMPTY LOOP BODY */
	}
}
void I2C_stop() {
	TWCR |= 1 << TWINT | 1 << TWSTO;
	TWCR &= ~(1 << TWEN);
}

void I2C_TXData(uint8_t data) {
	TWDR = data;
	TWCR = 1 << TWINT;
	while (!(TWCR & 1 << TWINT)) {
		/* EMPTY LOOP BODY */
	}
}

void I2C_TXByte(uint8_t device_addr, uint8_t data) {
	I2C_start();
	I2C_TXData(device_addr);
	I2C_TXData(data);
	I2C_stop();
}