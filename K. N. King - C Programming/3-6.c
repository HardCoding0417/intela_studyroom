// Adds two fractions and simplifies the result fraction
//
// Author: Choi Myeongsu
// Date: 2023-07-30




#include <stdio.h>



void reduce_fraction(int *, int *);


int main(){
	int numerator1, denominator1;
	int numerator2, denominator2;
	int res_numerator, res_denominator;

	printf("Enter two fractions seperated by a plus sign: ");
	scanf("%d /%d +%d /%d", &numerator1, &denominator1, &numerator2, &denominator2);

	res_numerator = numerator1*denominator2 + numerator2*denominator1;
	res_denominator = denominator1*denominator2;

	reduce_fraction(&res_numerator, &res_denominator);

	printf("\nSum of the two fractions: %d / %d\n", res_numerator, res_denominator);

	return 0;
}


void reduce_fraction(int *numerator, int *denominator){
	int reduced_numerator = *numerator, reduced_denominator = *denominator;

	int gcd = 1;
	int factor = 2;

	while(reduced_numerator >= factor){
		if(reduced_numerator % factor != 0 || reduced_denominator % factor != 0){
			++factor;
		}
		else{
			reduced_numerator /= factor;
			reduced_denominator /= factor;
			gcd *= factor;
		}
	}

	*numerator /= gcd;
	*denominator /= gcd;
}