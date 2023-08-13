// Displays the amount income tax of a single resident
// corresponding to the amount of income
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    double income;
    double tax_due;

    printf("Enter the amount of taxable income: ");
    scanf("%lf", &income);


    if (income < 750.) {
        tax_due = income * .01;
    }
    else if (income < 2250.) {
        tax_due = 7.5 + (income - 750.) * .02;
    }
    else if (income < 3750.) {
        tax_due = 37.5 + (income - 2250.) * .03;
    }
    else if (income < 5250.) {
        tax_due = 82.5 + (income - 3750.) * .04;
    }
    else if (income < 7000.) {
        tax_due = 142.5 + (income - 5250.) * .05;
    }
    else {
        tax_due = 230. + (income - 7000.) * .06;
    }

    printf("Tax due: %.2lf\n", tax_due);


    return 0;
}