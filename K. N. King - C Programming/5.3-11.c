// Prints corresponding major city with respect to area code
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int area_code = 76;

    switch (area_code) {
        case 229:
            printf("Albany\n");
            break;
        case 404: case 470: case 678: case 770:
            printf("Atlanta\n");
            break;
        case 478:
            printf("Macon\n");
            break;
        case 706: case 762:
            printf("Columbus\n");
            break;
        case 912:
            printf("Savannah\n");
            break;
        default:
            printf("Area code not recognized\n");
            break;
    }


    return 0;
}