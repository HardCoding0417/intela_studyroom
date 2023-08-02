// Prints float variable with different formats
//
// Author: Choi Myeongsu
// Date: 2023-07-29



#include <stdio.h>


int main(){
	float x;

	scanf("%f", &x);

	printf("\n%-8.1e\n", x);
	printf("%10.6e\n", x);
	printf("%-8.3f\n", x);
	printf("%6.0f\n", x);

	return 0;
}