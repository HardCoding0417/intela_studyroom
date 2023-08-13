// Calculates how many digits a number contains
// Assume that the number has no more than four digits
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int num, abs_num;
    int digit_cnt;

    printf("Enter a number: ");
    scanf("%hd", &num);


    abs_num = num >= 0 ? num : -num;

    if (abs_num < 10) {
        digit_cnt = 1;
    }
    else if (abs_num < 100) {
        digit_cnt = 2;
    }
    else if (abs_num < 1000) {
        digit_cnt = 3;
    }
    else {
        digit_cnt = 4;
    }

    printf("The number %d has %d digits\n", num, digit_cnt);


    return 0;
}