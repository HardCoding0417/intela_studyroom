// Prints a date in legal form
//
// Author: Choi Myeongsu
// Date: 2023-08-10




#include <stdio.h>

#define MONTH_CNT 12



int main(){
    signed char month, day, year_with_two_digits;

    char *ordinal_indicator;
    char *month_in_english[MONTH_CNT + 1] = {"",
        "January", "Feburary", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };


    printf("Enter date (mm/dd/yy): ");
    scanf("%hhd/%hhd/%hhd", &month, &day, &year_with_two_digits);


    //if (day / 10 != 1) {
    //    switch (day % 10) {
    //        case 1:
    //            ordinal_indicator = "st";
    //            break;
    //        case 2:
    //            ordinal_indicator = "nd";
    //            break;
    //        case 3:
    //            ordinal_indicator = "rd";
    //            break;
    //    }
    //}
    switch (day) {
        case 1: case 21: case 31:
            ordinal_indicator = "st";
            break;
        case 2: case 22:
            ordinal_indicator = "nd";
            break;
        case 3: case 23:
            ordinal_indicator = "rd";
            break;
        default:
            ordinal_indicator = "th";
            break;
    }


    printf("Dated this %d%s day of %s, 20%.2d.\n", day, ordinal_indicator,
           month_in_english[month], year_with_two_digits);


    return 0;
}