// Purpose: Computes the dimensional weight of a 12" x 10" x 8" box
// Author: Choi Myeongsu



#include <stdio.h>

#define CUBIC_INCHES_PER_POUND 166


int main(){
	int height = 8, length = 12, width = 10;
	int volume;

	volume = height*length*width;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n",
		   (volume + CUBIC_INCHES_PER_POUND - 1)/CUBIC_INCHES_PER_POUND);

	return 0;
}