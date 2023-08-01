#include <stdio.h>




int main(){
    short N, X;
    scanf("%hd %hd", &N, &X);

    short tg;
    for(short i = 0; i < N; ++i){
        scanf("%hd", &tg);
        if(tg < X) printf("%hd ", tg);
    }

    return 0;
}