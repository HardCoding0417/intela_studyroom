// Displays a number with its digits reversed
//
// Author: Choi Myeongsu
// Date: 2023-08-23




#include <stdio.h>



int main() {
    unsigned long long num;

    // MAX_NUM: 2^64 - 1
    printf("Enter an unsigned number: ");
    scanf("%llu", &num);


    printf("The reversal is: ");
    do {
        printf("%d", num % 10);
        num /= 10;
    } while (num != 0);
    putchar('\n');


    return 0;
}