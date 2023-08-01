#include <stdio.h>




int main(){
    int baskets[101] = {0};

    int N, M;
    scanf("%d %d", &N, &M);

    int i, j, k;
    for(int apt = 0; apt < M; ++apt){
        scanf("%d %d %d", &i, &j, &k);
        for(; i <= j; ++i) baskets[i] = k;
    }

    for(i = 1; i <= N; ++i) printf("%d ", baskets[i]);

    return 0;
}