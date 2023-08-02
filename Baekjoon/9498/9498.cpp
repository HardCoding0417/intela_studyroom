#include <iostream>




int main(){
    int score;
    scanf("%d", &score);

    char grade;
    if(score < 60) grade = 'F';
    else if(score < 70) grade = 'D';
    else if(score < 80) grade = 'C';
    else if(score < 90) grade = 'B';
    else grade = 'A';

    putchar(grade);

    return 0;
}