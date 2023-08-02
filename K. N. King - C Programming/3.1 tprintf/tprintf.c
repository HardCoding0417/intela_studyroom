// Prints int and float values in various formats
//
// Author: Choi Myeongsu
// Date: 2023-07-29



#include <stdio.h>


int main(){
	int i = 40;
	float x = 839.21f;

	printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
	// |40|   40|40   |  040|
	printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
	// |   839.210|   8.392e2|839.21    |

	return 0;
}