#include <stdio.h>




int main(){
    int N, X;
    scanf("%d %d", &N, &X);

    int tg;
    for(int i = 0; i < N; ++i){
        scanf("%d", &tg);
        if(tg < X) printf("%d ", tg);
    }

    return 0;
}