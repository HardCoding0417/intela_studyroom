#include <stdio.h>


#define INT_MAX 1000000




int main(){
    int N;
    scanf("%d", &N);

    int n;
    scanf("%d", &n);
    int min = n, max = n;
    for(int i = 1; i < N; ++i){
        scanf("%d", &n);
        if(n > max) max = n;
        else if(n < min) min = n;
    }

    printf("%d %d", min, max);

    return 0;
}