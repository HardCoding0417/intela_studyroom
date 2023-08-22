// Translated program fragment of Exercise 6.2-2
//
// Author: Choi Myeongsu
// Date: 2023-08-22



#include <stdio.h>


int main() {
    int i;

    for (i = 9384; i > 0; i /= 10) {
        printf("%d ", i);
    }

    return 0;
}