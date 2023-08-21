/*
 * Declare button macros, enums, and functions
 * Assume that the button is pull-up
 *
 * Created: 2023-08-21 오전 11:44:36
 *  Author: Choi Myeongsu
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_



// define the port for buttons
#define BUTTON_DDR DDRF
#define BUTTON_PIN PINF
#define BUTTON_PORT PORTF



// Button struct
typedef struct {
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	volatile uint8_t *port;
	uint8_t pin_num : 3;
	uint8_t prev_state : 1;
} Button;


enum ButtonState {RELEASE, PUSH};
enum ButtonAction {ACT_PUSH, ACT_RELEASE, NO_ACT};


void button_init(Button *, volatile uint8_t *, volatile uint8_t *, volatile uint8_t *, uint8_t);
uint8_t button_getAct(Button *);



#endif /* BUTTON_H_ */