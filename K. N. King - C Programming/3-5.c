// Asks the user to enter the numbers from 1 to 16 in any order
// and then displays the numbers in a 4x4 arrangement,
// followed by the sums of the rows, columns, and diagonals.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    int square_r0c0, square_r0c1, square_r0c2, square_r0c3;
    int square_r1c0, square_r1c1, square_r1c2, square_r1c3;
    int square_r2c0, square_r2c1, square_r2c2, square_r2c3;
    int square_r3c0, square_r3c1, square_r3c2, square_r3c3;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
          &square_r0c0, &square_r0c1, &square_r0c2, &square_r0c3,
          &square_r1c0, &square_r1c1, &square_r1c2, &square_r1c3,
          &square_r2c0, &square_r2c1, &square_r2c2, &square_r2c3,
          &square_r3c0, &square_r3c1, &square_r3c2, &square_r3c3);

    printf("\n%2d %2d %2d %2d\n",
           square_r0c0, square_r0c1, square_r0c2, square_r0c3);
    printf("%2d %2d %2d %2d\n",
           square_r1c0, square_r1c1, square_r1c2, square_r1c3);
    printf("%2d %2d %2d %2d\n",
           square_r2c0, square_r2c1, square_r2c2, square_r2c3);
    printf("%2d %2d %2d %2d\n\n",
           square_r3c0, square_r3c1, square_r3c2, square_r3c3);

    printf("Row sums: %d %d %d %d\n",
           square_r0c0 + square_r0c1 + square_r0c2 + square_r0c3,
           square_r1c0 + square_r1c1 + square_r1c2 + square_r1c3,
           square_r2c0 + square_r2c1 + square_r2c2 + square_r2c3,
           square_r3c0 + square_r3c1 + square_r3c2 + square_r3c3);
    printf("Column sums: %d %d %d %d\n",
           square_r0c0 + square_r1c0 + square_r2c0 + square_r3c0,
           square_r0c1 + square_r1c1 + square_r2c1 + square_r3c1,
           square_r0c2 + square_r1c2 + square_r2c2 + square_r3c2,
           square_r0c3 + square_r1c3 + square_r2c3 + square_r3c3);
    printf("Diagonal sums: %d %d\n",
           square_r0c0 + square_r1c1 + square_r2c2 + square_r3c3,
           square_r0c3 + square_r1c2 + square_r2c1 + square_r3c0);

    return 0;
}