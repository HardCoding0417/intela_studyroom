#include <stdio.h>
#include <string.h>




int main(){
	char fruit[11] = "strawberry";
	printf("%s\n", fruit);

	strcpy_s(fruit, sizeof(fruit), "banana");
	printf("%s\n", fruit);

	return 0;
}