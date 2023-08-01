// Computes 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 for given x.
//
// Author: Choi Myeongsu



#include <stdio.h>


int main(){
	double x;

	printf("Enter value of x: ");
	scanf("%lf", &x);

	printf("%.15g\n", ((((3.*x + 2.)*x - 5.)*x - 1.)*x + 7.)*x - 6.);

	return 0;
}