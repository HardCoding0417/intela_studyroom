// a program 'broker.c' of Section 5.2 that accepts inputs continuously
//
// Author: Choi Myeongsu
// Date: 2023-08-23



#include <stdio.h>


int main(){
    double trade_amount, commission_amount = 0.;


    while (1) {
        printf("Enter value of trade: ");
        scanf("%lf", &trade_amount);


        if (trade_amount == 0.) {
            break;
        }


        if(trade_amount < 2500.){
            commission_amount = 30. + trade_amount*.017;
            if(commission_amount < 39.){
                commission_amount = 39.;
            }
        }
        else if(trade_amount < 6250.){
            commission_amount = 56. + trade_amount*.0066;
        }
        else if(trade_amount < 20000.){
            commission_amount = 76. + trade_amount*.0034;
        }
        else if(trade_amount < 50000.){
            commission_amount = 100. + trade_amount*.0022;
        }
        else if(trade_amount < 500000.){
            commission_amount = 155. + trade_amount*.0011;
        }else{
            commission_amount = 255. + trade_amount*.0009;
        }

        printf("Commission: $%.2lf\n\n", commission_amount);
    }


    return 0;
}