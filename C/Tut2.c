#include <stdio.h>
#include <stdlib.h>

int main(){



    int marks[5];
    int total;

    for(int i = 0 ; i < 5 ; i++){
        printf("Enter marks for subject %d: " , i + 1);
        scanf("%d" , &marks[i]);
        total += marks[i];
    }

    int average = total / 5;
    char grade;

    switch (average)
    {
    case 0 ... 49:
        grade = 'F';
        break;
    case 50 ... 59:
        grade = 'E';
        break;
    case 60 ... 69:
        grade = 'D';
        break;
    case 70 ... 79:
        grade = 'C';
        break;
    case 80 ... 89:
        grade = 'B';
        break;
    case 90 ... 100:
        grade = 'A';
        break;

    default:
        printf("An error occured, maybe you put the wrong values? \n");
        break;
    }

    printf("Your average grade is: %c \n " , grade);

    return 0;
}
