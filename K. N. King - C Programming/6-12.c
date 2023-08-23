// Approximates mathematical constant 'e'
// until the current term becomes less than the number entered by a user
//
// Author: Choi Myeongsu
// Date: 2023-08-23




#include <stdio.h>



int main() {
    double sum_e = 1., add_term = 1.;
    double term_lowerBound;

    printf("Enter epsilon: ");
    scanf("%lf", &term_lowerBound);


    int k = 2;

    while (add_term >= term_lowerBound) {
        sum_e += add_term;
        add_term /= k;

        k++;
    }


    printf("yee: %.15g\n", sum_e);


    return 0;
}