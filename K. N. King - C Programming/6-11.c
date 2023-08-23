// Approximates mathematical constant 'e' until '1/n!' term is added to the sum
//
// Author: Choi Myeongsu
// Date: 2023-08-23




#include <stdio.h>



int main() {
    double sum_e = 1.;

    int n;
    double add_term = 1.;

    printf("Enter n: ");
    scanf("%d", &n);


    for (int k = 1; k <= n; k++) {
        add_term /= k;
        sum_e += add_term;
    }


    printf("yee: %.15g\n", sum_e);


    return 0;
}