// Finds the largest and smallest of four integers
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int num1, num2, num3, num4;
    int max_num1, min_num1, max_num2, min_num2;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);


    if (num1 > num2) {
        max_num1 = num1;
        min_num1 = num2;
    }
    else {
        max_num1 = num2;
        min_num1 = num1;
    }

    if (num3 > num4) {
        max_num2 = num3;
        min_num2 = num4;
    }
    else {
        max_num2 = num4;
        min_num2 = num3;
    }

    if (max_num2 > max_num1) {
        max_num1 = max_num2;
    }

    if (min_num2 < min_num1) {
        min_num1 = min_num2;
    }


    printf("Largest: %d\n", max_num1);
    printf("Smallest: %d\n", min_num1);


    return 0;
}