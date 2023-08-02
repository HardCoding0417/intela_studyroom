// Converts a Fahrenheit temperature to Celsius.
//
// Author: Choi Myeongsu



#include <stdio.h>

#define FREEZING_PT 32.f
#define SCALE_FACTOR (5.f / 9.f)


int main(){
	float fahrenheit, celsius;

	printf("Enter Fahrenheit temperature: ");
	scanf("%f", &fahrenheit);

	celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;

	printf("Celsius equivalent: %.1f\n", celsius);

	return 0;
}