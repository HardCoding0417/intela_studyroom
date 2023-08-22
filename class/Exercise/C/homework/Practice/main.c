#include <stdio.h>



int main() {
    char *str1 = "Hello";
    goto Here;

    {
        1 + 2;
Here:   ;
    }

    char *str2 = " world";
    printf("%s%s", str1, str2);


    return 0;
}