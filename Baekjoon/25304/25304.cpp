#include <iostream>




int main(){
    int X, N;
    scanf("%d %d", &X, &N);

    int a, b, sum = 0;
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &a, &b);
        sum += a*b;
    }

    if(X == sum) printf("Yes");
    else printf("No");

    return 0;
}