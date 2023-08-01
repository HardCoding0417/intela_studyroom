// Prints entered integer in octal.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    short num;

    printf("Enter a number between 0 and 32767: ");
    scanf("%hd", &num);

    printf("In octal, your number is: %.5ho\n", num);

    return 0;
}