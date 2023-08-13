// Prints the English word for the entered two-digit number
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int digit1, digit0;
    char *word1, *word0;

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &digit1, &digit0);

// eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
    if (digit1 == 1) {
        word1 = "";

        switch (digit0) {
            case 0: word0 = "ten";          break;
            case 1: word0 = "eleven";       break;
            case 2: word0 = "twelve";       break;
            case 3: word0 = "thirteen";     break;
            case 4: word0 = "fourteen";     break;
            case 5: word0 = "fifteen";      break;
            case 6: word0 = "sixteen";      break;
            case 7: word0 = "seventeen";    break;
            case 8: word0 = "eighteen";     break;
            case 9: word0 = "nineteen";     break;
        }
    }
    else {
        switch (digit1) {
            case 2: word1 = "twenty";       break;
            case 3: word1 = "thirty";       break;
            case 4: word1 = "forty";       break;
            case 5: word1 = "fifty";        break;
            case 6: word1 = "sixty";        break;
            case 7: word1 = "seventy";      break;
            case 8: word1 = "eighty";       break;
            case 9: word1 = "ninety";       break;
        }

        switch (digit0) {
            case 0: word0 = "";             break;
            case 1: word0 = "-one";         break;
            case 2: word0 = "-two";         break;
            case 3: word0 = "-three";       break;
            case 4: word0 = "-four";        break;
            case 5: word0 = "-five";        break;
            case 6: word0 = "-six";         break;
            case 7: word0 = "-seven";       break;
            case 8: word0 = "-eight";       break;
            case 9: word0 = "-nine";        break;
        }
    }

    printf("You entered the number %s%s.\n", word1, word0);


    return 0;
}