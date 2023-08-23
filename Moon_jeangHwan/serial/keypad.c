/*
 * keypad.c
 *
 * Created: 2023-08-22 오후 7:31:13
 *  Author: 문정환
 */ 

#include "keypad.h"

uint8_t rows[ROW_NUM] = {PORTD0, PORTD1, PORTD2, PORTD3}; // 행 핀
uint8_t cols[COL_NUM] = {PORTD4, PORTD5, PORTD6, PORTD7}; // 열 핀

char keys[ROW_NUM][COL_NUM] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

void keypad_init(void) // 초기화
{
	// 4개의 행 핀을 출력으로 설정, 4개의 열 핀을 입력으로 설정
	for (uint8_t i = 0; i < ROW_NUM; i++)	// 행핀의 DDRD를 1로 만듬(출력으로)
	{
		DDRD |= (1 << rows[i]);
	}
	for (uint8_t i = 0; i < COL_NUM; i++)	// 열핀의 DDRD를 0으로 만듬
	{
		DDRD &= ~(1 << cols[i]);
		PORTD |= (1 << cols[i]);			// 풀업저항 활성화 (=버튼을 누르면 PORTD가 0이 되도록 했다는 뜻)
	}
}

char keypad_scan(void)	// 입력을 감지하는 함수
{
	// 이것을 구현하기 위해 시도한 내 전략은
	// 행을 하나 씩 0으로 만들면서 해당 행의 열이 0인지 체크하는 것이다.
	// COL이 0이라면 버튼이 눌린 것임
    // 버튼을 눌러보면서 생각해보면 알기 쉽다.

	for (uint8_t row = 0; row < ROW_NUM; row++) // 0~행만큼 순회
	{
		PORTD &= ~(1 << rows[row]); // 현재 행의 PORT를 0으로 바꿈. 나머지는 그대로
        for (uint8_t col = 0; col < COL_NUM; col++)  // 해당 행의 COL이 0인지 확인
		{
			if (!(PIND & (1 << cols[col]))) // PORTD의 값이 해당 열과 같고, 그것이 버튼이 눌렸을 때의 값이라면
			{
				PORTD |= (1 << rows[row]);	// 행을 다시 HIGH로 설정하고
				return keys[row][col];		// 해당 키를 반환. 이로서 어떤 버튼이 눌렸는지 알아낼 수 있다.
			}
		}
		PORTD |= (1 << rows[row]);			// 해당 행을 다시 HIGH로 설정
	}
	return 0; // 키가 눌리지 않았으면 0 반환
}



// 컴퓨터와 통신하기 위한 시리얼 통신 함수 3개 (https://m.blog.naver.com/seo0511/221115028097)

void USART_Init(unsigned int ubrr) // 초기화 함수.
{
	UBRR0H = (ubrr >> 8);	// UBBR에 baud rate 넣어줌
	UBRR0L = ubrr;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0); // 수신 및 전송 활성화
	UCSR0C = (3 << UCSZ00); // 8비트 데이터 형식
}

void USART_Transmit(unsigned char data)
{
	while (!(UCSR0A & (1 << UDRE0))); // 전송 버퍼가 빌 때까지 대기
	UDR0 = data; // 데이터 전송
}

unsigned char USART_Receive(void)
{
	while (!(UCSR0A & (1 << RXC0))); // 데이터 수신 대기
	return UDR0; // 수신 받은 데이터 반환
}
