// Converts a numerical grade into a letter grade with switch statement
//
// Author: Choi Myeongsu
// Date: 2023-08-13




#include <stdio.h>



int main() {
    int num_grade;
    char letter_grade;

    printf("Enter numerical grade: ");
    scanf("%d", &num_grade);


    if (num_grade > 100 || num_grade < 0) {
        printf("Invalid grade\n");
    }
    else {
        switch (num_grade / 10) {
            case 10: case 9:
                letter_grade = 'A';
                break;
            case 8:
                letter_grade = 'B';
                break;
            case 7:
                letter_grade = 'C';
                break;
            case 6:
                letter_grade = 'D';
                break;
            default:
                letter_grade = 'F';
                break;
        }

        printf("Letter grade: %c\n", letter_grade);
    }


    return 0;
}