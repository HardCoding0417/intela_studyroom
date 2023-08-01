#include <iostream>




int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int prize;
    if(a == b){
        prize = 100*(10 + a);
        if(a == c) prize *= 10;
    }else if(b == c) prize = 100*(10 + b);
    else if(a == c) prize = 100*(10 + a);
    else prize = 100*(a > b ? (a > c ? a : c) : (b > c ? b : c));

    printf("%d", prize);

    return 0;
}