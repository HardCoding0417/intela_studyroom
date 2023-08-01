#include <stdio.h>




int main(){
    signed char N;
    scanf("%d", &N);

    for(signed char j = 0; j < N; ++j){
        for(signed char i = -1; i < j; ++i) putchar('*');
        putchar('\n');
    }

    return 0;
}