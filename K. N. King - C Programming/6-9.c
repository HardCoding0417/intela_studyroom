// Calculates the remaining balance on monthly payments
//
// Author: Choi Myeongsu
// Date: 2023-08-23




#include <stdio.h>



int main(){
	double loan, interest_rate, monthly_payment;
    int num_payments;

	printf("Enter amount of loan: ");
	scanf("%lf", &loan);
	printf("Enter interest rate: ");
	scanf("%lf", &interest_rate);
    printf("Enter the number of monthly payments: ");
    scanf("%d", &num_payments);

	interest_rate /= 12;
	

    putchar('\n');
    for (int payment_idx = 0; payment_idx < num_payments; payment_idx++) {
        printf("Enter monthly payment: ");
        scanf("%lf", &monthly_payment);

        printf("Balance remaining after first payment: $%.2lf\n",
            loan += loan*interest_rate/100. - monthly_payment);
    }


	return 0;
}