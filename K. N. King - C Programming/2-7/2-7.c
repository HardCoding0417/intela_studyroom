// Shows the way to pay given U.S. dollar amount with $20, $10, $5, and $1.
//
// Author: Choi Myeongsu



#include <stdio.h>


int main(){
	int dollar_amount;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	printf("\n$20 bills: %d\n", dollar_amount / 20);
	dollar_amount %= 20;
	printf("$10 bills: %d\n", dollar_amount / 10);
	dollar_amount %= 10;
	printf(" $5 bills: %d\n", dollar_amount / 5);
	dollar_amount %= 5;
	printf(" $1 bills: %d\n", dollar_amount);

	return 0;
}