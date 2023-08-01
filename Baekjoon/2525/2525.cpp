#include <iostream>




int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    
    A += C/60;
    B += C%60;

    if(B > 59){
        B -= 60;
        ++A;
    }
    if(A > 23) A -= 24;


    printf("%d %d", A, B);

    return 0;
}