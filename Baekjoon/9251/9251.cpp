#include <iostream>
#include <cstring>
#include <algorithm>


#define MAX_STRING_LENGTH 1000




int main(){
    char s1[MAX_STRING_LENGTH + 2], s2[MAX_STRING_LENGTH + 2];
    short arr[MAX_STRING_LENGTH + 1][MAX_STRING_LENGTH + 2] = {0};

    scanf("%s\n%s", s1 + 1, s2 + 1);

    int len1 = strlen(s1) - 1, len2 = strlen(s2) - 1;


    char c;
    int updated_val;
    for(int idx2 = 1, idx1; idx2 <= len2; ++idx2){
        c = s2[idx2];
        idx1 = 1;

        while(idx1 <= len1){
            if(s1[idx1] == c)
                updated_val = arr[idx2][idx1] = arr[idx2 - 1][idx1 - 1] + 1;
            else
                arr[idx2][idx1] = std::max(arr[idx2 - 1][idx1], arr[idx2][idx1 - 1]);
            ++idx1;
        }
    }

    printf("%d", arr[len2][len1]);


    return 0;
}