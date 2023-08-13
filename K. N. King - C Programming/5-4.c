// Displays the description of Beaufort scale with entered wind speed in knots
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    double wind_speed;
    char *description;

    printf("Enter a wind speed in knots: ");
    scanf("%lf", &wind_speed);


    if (wind_speed < 1.) {
        description = "Calm";
    }
    else if (wind_speed < 4.) {
        description = "Light air";
    }
    else if (wind_speed < 28.) {
        description = "Breeze";
    }
    else if (wind_speed < 48.) {
        description = "Gale";
    }
    else if (wind_speed < 64.) {
        description = "Storm";
    }
    else {
        description = "Hurricane";
    }

    printf("%s\n", description);


    return 0;
}