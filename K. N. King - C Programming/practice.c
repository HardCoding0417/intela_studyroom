#include <stdio.h>


int main(){
    int i, j;

    i = 7;
    j = 3 + --i * 2;
    printf("%d %d", i, j);

    return 0;
}