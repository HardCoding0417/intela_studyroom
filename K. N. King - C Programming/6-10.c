// Determines which of dates comes earliest on the calendar
//
// Author: Choi Myeongsu
// Date: 2023-08-23




#include <stdio.h>
#include <stdbool.h>



int main() {
    int month_earliest, day_earliest, year_earliest;
    int month, day, year;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month_earliest, &day_earliest, &year_earliest);

    if (!(month_earliest || day_earliest || year_earliest)) {
        printf("No dates were entered\n");
        return 0;
    }


    bool is_earlier;

    while (1) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);

        if (!(month || day || year)) {
            break;
        }


        is_earlier = false;

        if (year < year_earliest) {
            is_earlier = true;
        }
        else if (year == year_earliest) {
            if (month < month_earliest) {
                is_earlier = true;
            }
            else if (month_earliest == month) {
                if (day < day_earliest) {
                    is_earlier = true;
                }
            }
        }

        if (is_earlier) {
            year_earliest = year;
            month_earliest = month;
            day_earliest = day;
        }
    }
    

    printf("%d/%d/%.2d is the earliest date\n", month_earliest, day_earliest, year_earliest);


    return 0;
}