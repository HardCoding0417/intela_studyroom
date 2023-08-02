// Computes the volume of a sphere with 10-meter radius.
//
// Author: Choi Myeongsu
// Date: 2023-07-25



#include <stdio.h>

#define PI 3.14159f


int main(){
	float radius, volume;
	
	printf("Enter the radius of sphere: ");
	scanf("%f", &radius);

	volume = 4.f / 3.f * PI * radius*radius*radius;

	printf("The volume of a sphere with 10-meter radius: %.2fm^3\n", volume);

	return 0;
}