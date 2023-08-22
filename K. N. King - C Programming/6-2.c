// Displays the greatest common divisor(GCD) of two integers
//
// Author: Choi Myeongsu
// Date: 2023-08-22




#include <stdio.h>



int main() {
    int m, n, r;

    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("Greatest common divisor: %d\n", m);


    return 0;
}