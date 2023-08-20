// Improved 6.1 square.c by replacing the 'while' loop to a 'for' loop
//
// Author: Choi Myeongsu
// Date: 2023-08-20




#include <stdio.h>



int main() {
    int n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    
    for (int i = 1; i <= n; i++) {
        printf("%11d %11d\n", i, i * i);
    }


    return 0;
}