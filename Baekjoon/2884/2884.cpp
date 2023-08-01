#include <iostream>




int main(){
    int H, M;
    scanf("%d %d", &H, &M);

    M -= 45;
    if(M < 0){
        M += 60;
        H = H ? H - 1 : 23;
    }

    printf("%d %d", H, M);

    return 0;
}