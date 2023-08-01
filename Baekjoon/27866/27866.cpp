#include <stdio.h>


#define MAX_WORDLENGTH 1000




int main(){
    char word[MAX_WORDLENGTH + 1];
    scanf("%s", word);

    int i;
    scanf("%d", &i);


    putchar(word[i - 1]);


    return 0;
}