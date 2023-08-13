// Calculates a broker's commission and a rival broker's commision
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main(){
    int share_cnt;
    double share_price;

    double trade_amount, commission_amount;
    double commision_amount_r;


    printf("Enter the number of shares and the price per share: ");
    scanf("%d %lf", &share_cnt, &share_price);

    trade_amount = share_cnt * share_price;


    if (trade_amount < 2500.) {
        commission_amount = 30. + trade_amount*.017;
        if (commission_amount < 39.) {
            commission_amount = 39.;
        }
    }
    else if (trade_amount < 6250.) {
        commission_amount = 56. + trade_amount*.0066;
    }
    else if (trade_amount < 20000.) {
        commission_amount = 76. + trade_amount*.0034;
    }
    else if (trade_amount < 50000.) {
        commission_amount = 100. + trade_amount*.0022;
    }
    else if (trade_amount < 500000.) {
        commission_amount = 155. + trade_amount*.0011;
    }
    else {
        commission_amount = 255. + trade_amount*.0009;
    }

    commision_amount_r = 33 + share_cnt * (share_cnt < 2000 ? .03 : .02);


    printf("Commission: $%.2lf\n", commission_amount);
    printf("Rival's Commision: $%.2lf\n", commision_amount_r);


    return 0;
}