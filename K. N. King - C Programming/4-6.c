// Computes a European Article Number check digit
// when the first 12 digits of the code is given from the input.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    int ean_digit1, ean_digit2, ean_digit3, ean_digit4, ean_digit5, ean_digit6;
    int ean_digit7, ean_digit8, ean_digit9, ean_digit10, ean_digit11, ean_digit12;

    printf("Enter the first 12 digits of a ean: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
            &ean_digit1, &ean_digit2, &ean_digit3, &ean_digit4, &ean_digit5, &ean_digit6,
            &ean_digit7, &ean_digit8, &ean_digit9, &ean_digit10, &ean_digit11, &ean_digit12);

    printf("Check digit: %d\n",
        9 - ( (ean_digit2 + ean_digit4 + ean_digit6 + ean_digit8 + ean_digit10 + ean_digit12) * 3 
        + (ean_digit1 + ean_digit3 + ean_digit5 + ean_digit7 + ean_digit9 + ean_digit11) - 1 ) % 10 );

    return 0;
}