#include <stdio.h>




int main(){
    int N;
    scanf("%d", &N);

    for(int j = 1; j <= N; ++j){
        int i;
        for(i = N; i > j; --i) putchar(' ');
        for(i = 0; i < j; ++i) putchar('*');
        putchar('\n');
    }

    return 0;
}