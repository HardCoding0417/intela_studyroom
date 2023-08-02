#include <stdio.h>


#define TOTAL_STUDENT 30
#define SOLVED_STUDENT (TOTAL_STUDENT - 2)




int main(){
    bool solved[TOTAL_STUDENT + 1] = {false};

    int idx;
    for(int i = 1; i <= SOLVED_STUDENT; ++i){
        scanf("%d", &idx);
        solved[idx] = true;
    }

    for(int i = 1; i <= TOTAL_STUDENT; ++i) if(!solved[i]) printf("%d\n", i);

    return 0;
}