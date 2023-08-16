// Sums a series of integers entered by the user
//
// Author: Choi Myeongsu
// Date: 2023-08-15




#include <stdio.h>



int main() {
    int sum = 0;
    int num;

    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");


    do {
        scanf("%d", &num);
        sum += num;
    } while (num);


    printf("The sum is: %d\n", sum);


    return 0;
}