// Computes a Universal Product Code check digit
// when the first 11 digits of the code is given from the input.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    int upc_digit1;
    int upc_digit2, upc_digit3, upc_digit4, upc_digit5, upc_digit6;
    int upc_digit7, upc_digit8, upc_digit9, upc_digit10, upc_digit11;

    printf("Enter the first (single) digit: ");
    scanf("%d", &upc_digit1);
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%d",
            &upc_digit2, &upc_digit3, &upc_digit4, &upc_digit5, &upc_digit6);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%d",
            &upc_digit7, &upc_digit8, &upc_digit9, &upc_digit10, &upc_digit11);

    printf("Check digit: %d\n",
            9 - ( (upc_digit1 + upc_digit3 + upc_digit5 + upc_digit7 + upc_digit9 + upc_digit11) * 3 
                + (upc_digit2 + upc_digit4 + upc_digit6 + upc_digit8 + upc_digit10) - 1 ) % 10 );

    return 0;
}