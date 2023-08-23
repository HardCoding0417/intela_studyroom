// Reduces the fraction to lowest terms
//
// Author: Choi Myoengsu
// Date: 2023-08-23




#include <stdio.h>



int main() {
    int numerator, denominator;

    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denominator);


    // Gets the Greatest Common Divisor(GCD) of the two numbers
    int gcd;
    {
        int m = numerator, n = denominator, r;

        while (n != 0) {
            r = m % n;
            m = n;
            n = r;
        }

        gcd = m;
    }


    printf("In lowest terms: %d/%d\n", numerator / gcd, denominator / gcd);


    return 0;
}