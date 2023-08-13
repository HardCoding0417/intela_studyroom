// Checks whether a UPC is valid
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main(){
    int upc_digit1;
    int upc_digit2, upc_digit3, upc_digit4, upc_digit5, upc_digit6;
    int upc_digit7, upc_digit8, upc_digit9, upc_digit10, upc_digit11;
    int upc_digit12;

    printf("Enter a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &upc_digit1,
            &upc_digit2, &upc_digit3, &upc_digit4, &upc_digit5, &upc_digit6,
            &upc_digit7, &upc_digit8, &upc_digit9, &upc_digit10, &upc_digit11,
            &upc_digit12);

 
    printf("%s\n", upc_digit12 ==
            9 - ( (upc_digit1 + upc_digit3 + upc_digit5 + upc_digit7 + upc_digit9 + upc_digit11) * 3 
                + (upc_digit2 + upc_digit4 + upc_digit6 + upc_digit8 + upc_digit10) - 1 ) % 10
            ? "VALID" : "NOT VALID");

 
    return 0;
}