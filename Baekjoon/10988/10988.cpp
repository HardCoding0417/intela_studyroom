#include <iostream>
#include <cstring>


#define MAX_WORD_SIZE 100




int main(){
    char word[MAX_WORD_SIZE + 1];
    scanf("%s", word);

    int front = 0, end = (int) strlen(word) - 1;
    bool is_palindrome = true;
    while(front < end){
        if(word[front++] != word[end--]){
            is_palindrome = false;
            break;
        }
    }

    printf("%d", is_palindrome);

    return 0;
}