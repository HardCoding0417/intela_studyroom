// Prints all even squares between 1 and n
//
// Author: Choi Myonegsu
// Date: 2023-08-23




#include <stdio.h>



int main() {
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);


    {
        int i = 2, i_squared = 4;
        while (i_squared <= n) {
            printf("%d\n", i_squared);

            i += 2;
            i_squared = i * i;
        }
        putchar('\n');
    }


    return 0;
}