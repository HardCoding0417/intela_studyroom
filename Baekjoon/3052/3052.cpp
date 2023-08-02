#include <stdio.h>


#define TOTAL_COUNT 10
#define DIVIDER 42




int main(){
    bool rem[DIVIDER] = {false};
    int n, r, cnt = 0;
    for(int i = 0; i < TOTAL_COUNT; ++i){
        scanf("%d", &n);
        r = n%DIVIDER;

        if(!rem[r]){
            rem[r] = true;
            ++cnt;
        }
    }

    printf("%d", cnt);

    return 0;
}