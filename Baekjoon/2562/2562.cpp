#include <stdio.h>




int main(){
    int n, max;
    scanf("%d", &max);
    int max_idx = 0;

    for(int i = 1; i < 9; ++i){
        scanf("%d", &n);
        if(n > max){
            max_idx = i;
            max = n;
        }
    }

    printf("%d %d", max, max_idx + 1);

    return 0;
}