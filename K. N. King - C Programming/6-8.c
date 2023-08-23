// Prints a one-month calendar
//
// Author: Choi Myeongsu
// Date: 2023-08-23




#include <stdio.h>



int main() {
    int num_of_days, col;

    printf("Enter number of days in month: ");
    scanf("%d", &num_of_days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &col);



    for (int i = 1; i < col; i++) {
        printf("   ");
    }
    for (int day = 1; day <= num_of_days; day++) {
        printf("%3d", day);
        
        col++;
        
        if (col > 7) {
            putchar('\n');
            col = 1;
        }
    }
    if (col != 1) {
        putchar('\n');
    }


    return 0;
}