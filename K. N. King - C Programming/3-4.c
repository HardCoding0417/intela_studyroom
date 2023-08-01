// Prompts the user to enter a telephone number in the form (xxx) xxx-xxxx
// and then displays the number in the form xxx.xxx.xxxx
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    short phone_num1, phone_num2, phone_num3;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%hd)%hd-%hd", &phone_num1, &phone_num2, &phone_num3);

    printf("You entered %.3hd.%.3hd.%.4hd\n", phone_num1, phone_num2, phone_num3);

    return 0;
}