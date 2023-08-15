// Calculates the number of digits in an integer
//
// Author: Choi Myeongsu
// Date: 2023-08-15




#include <stdio.h>



int main() {
    int num;
    int digit_cnt = 0;
    
    printf("Enter an integer: ");
    scanf("%d", &num);


    do {
        num /= 10;
        ++digit_cnt;
    } while (num);


    printf("The number has %d digit(s).\n", digit_cnt);


    return 0;
}