// Asks the user for a 24-hour time and then display the time in 12-hour form
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int hour, min;
    char *postfix;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);


    postfix = hour >= 12 ? "PM" : "AM";

    if (hour == 0) {
        hour = 12;
    }
    if (hour > 12) {
        hour -= 12;
    }


    printf("Equivalent 12-hour time: %d:%.2d %s\n", hour, min, postfix);


    return 0;
}