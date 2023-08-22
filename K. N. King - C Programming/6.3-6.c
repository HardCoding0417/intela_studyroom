// Translated program fragment of Exercise 6.1-1
//
// Author: Choi Myeongsu
// Date: 2023-08-22



#include <stdio.h>


int main() {
    int i;

    for (i = 1; i <= 128; i *= 2) {
        printf("%d ", i);
    }

    return 0;
}