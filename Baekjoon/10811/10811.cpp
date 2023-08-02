#include <stdio.h>

#include <utility>


#define MAX_BASKET 100




int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int baskets[MAX_BASKET + 1];
    for(int idx = 1; idx <= N; ++idx) baskets[idx] = idx;

    int i, j;
    for(int atp = 0; atp < M; ++atp){
        scanf("%d %d", &i, &j);
        while(i < j){
            std::swap(baskets[i], baskets[j]);
            ++i, --j;
        }
    }

    for(int idx = 1; idx <= N; ++idx) printf("%d ", baskets[idx]);

    return 0;
}