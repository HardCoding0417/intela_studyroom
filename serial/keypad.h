/*
 * keypad.h
 *
 * Created: 2023-08-22 오후 7:31:34
 *  Author: 문정환
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUD 9600		// UART를 통해 초당 9600번의 신호를 주고 받도록 설정.
#define MYUBRR F_CPU/16/BAUD-1	// 위의 주석대로 수치들을 입력함. 이로서 UBBR에 정확한 값을 넣을 수 있다. (이 경우는 103)

#define ROW_NUM 4
#define COL_NUM 4

extern uint8_t rows[ROW_NUM];
extern uint8_t cols[COL_NUM];
extern char keys[ROW_NUM][COL_NUM];

void keypad_init(void); // 키패드 초기화
char keypad_scan(void);	// 입력 받았는지 체크
void USART_Init(unsigned int ubrr); // USART 초기화
void USART_Transmit(unsigned char data); // 송신함수
unsigned char USART_Receive(void);		 // 수신함수

#endif /* KEYPAD_H_ */