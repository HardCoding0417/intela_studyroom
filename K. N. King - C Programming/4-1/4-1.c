// Prints entered two-digit number with its digits reversed.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    char digit1, digit2;

    printf("Enter a two-digit number: ");
    scanf("%1hhd%1hhd", &digit1, &digit2);

    printf("The reversal is: %hhd%hhd\n", digit2, digit1);

    return 0;
}