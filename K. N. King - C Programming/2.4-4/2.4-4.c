// Prints garbage values from uninitialized integer and floating point variables
//
// Author: Choi Myeongsu



#include <stdio.h>

#pragma warning(disable:4700)


int main(){
	int int1, int2, int3;
	float float1, float2, float3;

	printf("%d %d %d\n", int1, int2, int3);
	printf("%f %f %f", float1, float2, float3);

	return 0;
}