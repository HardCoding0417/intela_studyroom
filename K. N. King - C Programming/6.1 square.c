// Prints a table of squares
//
// Author: Choi Myeongsu
// Date: 2023-08-15




#include <stdio.h>



int main() {
    int n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);


    int i = 1;
    while (i <= n) {
        printf("%11d %11d\n", i, i * i);
        ++i;
    }


    return 0;
}