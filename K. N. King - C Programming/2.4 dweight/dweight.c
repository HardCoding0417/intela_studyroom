// Purpose: Computes the dimensional weight of a 12" x 10" x 8" box
// Author: Choi Myeongsu



#include <stdio.h>


int main(){
	int height, length, width;

	height = 8;
	length = 12;
	width = 10;

	int volume, weight;

	volume = height*length*width;
	weight = (volume + 165)/166;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);

	return 0;
}