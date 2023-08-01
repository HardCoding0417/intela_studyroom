// Formats product information entered by the user.
//
// Author: Choi Myonegsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    int item_num;
    float unit_price;
    int purchase_year, purchase_month, purchase_day;

    printf("Enter item number: ");
    scanf("%d", &item_num);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &purchase_month, &purchase_day, &purchase_year);

    printf("\nItem\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%-16d$%7.2f\t%.2d/%.2d/%.4d\n", item_num, unit_price, purchase_month,
                                            purchase_day, purchase_year);

    return 0;
}