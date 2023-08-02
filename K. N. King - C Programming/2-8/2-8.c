// Calculates the remaining balance on a loan when interest rate and monthly payment
// are given.
//
// Author: Choi Myeongsu



#include <stdio.h>


int main(){
	double loan, interest_rate, monthly_payment;

	printf("Enter amount of loan: ");
	scanf("%lf", &loan);
	printf("Enter interest rate: ");
	scanf("%lf", &interest_rate);
	printf("Enter monthly payment: ");
	scanf("%lf", &monthly_payment);

	interest_rate /= 12;

	printf("\nBalance remaining after first payment: $%.2lf\n",
		   loan += loan*interest_rate/100. - monthly_payment);
	printf("Balance remaining after second payment: $%.2lf\n",
		   loan += loan*interest_rate/100. - monthly_payment);
	printf("Balance remaining after third payment: $%.2lf\n",
		   loan*(1. + interest_rate/100.) - monthly_payment);

	return 0;
}