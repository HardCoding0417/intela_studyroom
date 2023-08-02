// Computes the dimensional weight of a box from input provided by the user
// 
// Author: Choi Myeongsu
// Date: 2023-07-25



#include <stdio.h>

#define INCHES_PER_POUND 166



int main(){
	int length, width, height;

	printf("Enter height of box: ");
	scanf("%d", &height);
	printf("Enter length of box: ");
	scanf("%d", &length);
	printf("Enter width of box: ");
	scanf("%d", &width);


	int volume = length*width*height;
	int weight = (volume + INCHES_PER_POUND - 1)/INCHES_PER_POUND;


	printf("\nVolume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);


	return 0;
}