// Adds two fractions
//
// Author: Choi Myeongsu
// Date: 2023-07-29



#include <stdio.h>


int main(){
	int numerator1, denominator1;
	int numerator2, denominator2;

	printf("Enter the first fraction: ");
	scanf("%d /%d", &numerator1, &denominator1);
	printf("Enter the second fraction: ");
	scanf("%d /%d", &numerator2, &denominator2);

	printf("\nSum of the two fractions: %d / %d\n",
		   numerator1*denominator2 + numerator2*denominator1, denominator1*denominator2);

	return 0;
}