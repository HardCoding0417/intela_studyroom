// Finds the largest in a series of numbers entered by a user
//
// Author: Choi Myeongsu
// Date: 2023-08-22




#include <stdio.h>



int main() {
    double fpNum, fpNum_max = 0.;

    while (1) {
        printf("Enter a number: ");
        scanf("%lf", &fpNum);

        if (fpNum <= 0.) {
            break;
        }

        if (fpNum > fpNum_max) {
            fpNum_max = fpNum;
        }
    }

    printf("\nThe largest number entered was %.15g\n", fpNum_max);


    return 0;
}