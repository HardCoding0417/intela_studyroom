// Displays the departure and arrival times for the flight closest to the time entered
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int hour, min;
    int tot_min;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);


    tot_min = hour * 60 + min;

    if (tot_min >= 1223 || tot_min < 173) {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }
    else if (tot_min < 532) {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (tot_min < 631) {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (tot_min < 723) {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    }
    else if (tot_min < 804) {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (tot_min < 893) {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (tot_min < 1043) {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    }

    
    return 0;
}