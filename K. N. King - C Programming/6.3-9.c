// Translated program fragment of Exercise 6.3-8
//
// Author: Choi Myeongsu
// Date: 2023-08-22



#include <stdio.h>


int main() {
    int i;

    i = 10;
    while (i >= 1) {
        printf("%d ", i);

        i++;
        i /= 2;
    }

    return 0;
}