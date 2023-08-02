// Adds tax onto the amount of input.
//
// Author: Choi Myeongsu
// Date: 2023-07-25



#include <stdio.h>

#define TAX_WEIGHT 1.05f


int main(){
	float amount;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	printf("With tax added: $%.2f\n", amount * TAX_WEIGHT);

	return 0;
}