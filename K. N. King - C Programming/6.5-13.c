// An example of a loop whose body is empty
//
// Author: Choi Myeongsu
// Date: 2023-08-22



#include <stdio.h>


int main() {
    int n, m = 10;

    for (n = 0; m > 0; m /= 2, n++) {
        /* EMPTY LOOP BODY */
    }

    m = 10;

    for (n = 0; m > 0; n++) {
        m /= 2;
    }

    return 0;
}