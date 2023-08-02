// Accepts a date from the user in the form mm/dd/yyyy and then displays it in the form yyyymmdd.
//
// Author: Choi Myeongsu
// Date: 2023-07-30



#include <stdio.h>


int main(){
    int year, month, day;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &month, &day, &year);

    printf("You entered the date %.4d%.2d%.2d\n", year, month, day);

    return 0;
}