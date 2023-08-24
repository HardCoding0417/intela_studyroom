/*
 * 4x4keypad2.c
 *
 * Created: 2023-08-22 오후 4:42:43
 * Author : 문정환
 */ 

// 버튼의 사양이 달라져도 쉽게 적용할 수 있도록
// 코드의 유연성을 높혔음

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "keypad.h"

int main(void) 
{
	keypad_init();
	USART_Init(MYUBRR);

	while (1) 
	{
		char key = keypad_scan();
		if (key)
		{
			USART_Transmit(key); // 키 눌림을 USART를 통해 전송
			_delay_ms(200); // 디바운싱 대기
		}
	}

	return 0;
}
