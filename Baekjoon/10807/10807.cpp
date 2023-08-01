#include <stdio.h>




int main(){
    int cnt[201] = {0};

    int N;
    scanf("%d", &N);

    int n;
    for(int i = 0; i < N; ++i){
        scanf("%d", &n);
        ++cnt[n + 100];
    }

    scanf("%d", &n);
    printf("%d", cnt[n + 100]);

    return 0;
}