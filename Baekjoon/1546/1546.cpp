#include <stdio.h>




int main(){
    int N;
    scanf("%d", &N);

    int sum = 0, max = 0;
    int score;
    for(int i = 0; i < N; ++i){
        scanf("%d", &score);

        sum += score;
        if(score > max) max = score;
    }

    printf("%.2lf", (double)(sum*100)/N/max);

    return 0;
}