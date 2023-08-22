// Maintains a checkbook balance
//
// Author: Choi Myeongsu
// Date: 2023-08-22




#include <stdio.h>
#include <stdlib.h>



int main() {
    printf("*** ACME checkbook-balancing program ***\n");
    printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");

    double balance = 0.;
    double amount;

    int cmd;
    while (1) {
        printf("Enter command: ");
        scanf("%d", &cmd);

        switch (cmd) {
            case 0:
                balance = 0.;
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%lf", &amount);
                
                balance += amount;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%lf", &amount);

                balance -= amount;
                break;
            case 3:
                printf("Current balance: $%.2lf\n", balance);
                break;
            case 4:
                return 0;
            default:
                printf("\nCommands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
                break;
        }
    }


    return 0;
}