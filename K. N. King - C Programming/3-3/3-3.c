// Breaks down an ISBN entered by the user and prints them.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    int item_num;
    short GS1_prefix, publisher_code;
    signed char group_idx, check_digit;

    printf("Enter ISBN: ");
    scanf("%hd-%hhd-%hd-%d-%hhd", &GS1_prefix, &group_idx, &publisher_code, &item_num, &check_digit);

    printf("\nGS1 prefix: %d\n", GS1_prefix);
    printf("Group identifier: %d\n", group_idx);
    printf("Publisher code: %.3d\n", publisher_code);
    printf("Item number: %.5d\n", item_num);
    printf("Check digit: %d\n", check_digit);

    return 0;
}