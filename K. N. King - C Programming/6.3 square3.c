// Prints a table of squares using an odd method
//
// Author: Choi Myeongsu
// Date: 2023-08-20




#include <stdio.h>



#include <stdio.h>



int main() {
    int n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    
    int i, square = 1, odd = 3;

    for (i = 1; i <= n; i++) {
        printf("%11d %11d\n", i, square);

        square += odd;
        odd += 2;
    }


    return 0;
}