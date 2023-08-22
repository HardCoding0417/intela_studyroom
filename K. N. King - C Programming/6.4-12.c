// Refactors prime-testing loop appeared in Section 6.4
//
// Author: Choi Myeongsu
// Date: 2023-08-22



#include <stdio.h>


int main() {
    int d, n = 1357;

    for (d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            break;
        }
    }

    if (d * d > n) {
        printf("prime\n");
    }
    else {
        printf("optimus prime %d\n", d);
    }

    return 0;
}