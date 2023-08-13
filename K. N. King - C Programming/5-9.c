// Indicates which date comes earlier when two dates are given
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>
#include <stdbool.h>



int main() {
    int month1, day1, year1;
    int month2, day2, year2;

    bool is_earlier = true;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);


    if (year1 > year2) {
        is_earlier = false;
    }
    else if (year1 == year2) {
        if (month1 > month2) {
            is_earlier = false;
        }
        else if (month1 == month2) {
            if (day1 > day2) {
                is_earlier = false;
            }
        }
    }


    if (is_earlier) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month1, day1, year1,
                month2, day2, year2);
    }
    else {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month2, day2, year2,
                month1, day1, year1);
    }


    return 0;
}