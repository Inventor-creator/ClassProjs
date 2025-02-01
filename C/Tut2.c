#include <stdio.h>  
#include <stdlib.h>

int main(){

    //Q1:

    // int currentYear , joiningYear;

    // printf("Enter The current year: ");
    // scanf("%d" , &currentYear);
    // printf("Enter Your joining year: ");
    // scanf("%d" , &joiningYear);

    // int yearsServed = currentYear - joiningYear;

    // if(yearsServed <= 3 && yearsServed >= 0){
    //     printf("Your Bonus is 1000\n");
    // }
    // else if(yearsServed <6){
    //     printf("Your Bonus is 2500\n");
    // }
    // else if(yearsServed < 10){
    //     printf("Your Bonus is 5000\n");
    // }
    // else{
    //     printf("Your Bonus is 10000\n");
    // }

    //Q2
    

    // int marks[5];
    // int total;

    // for(int i = 0 ; i < 5 ; i++){
    //     printf("Enter marks for subject %d: " , i + 1);
    //     scanf("%d" , &marks[i]);
    //     total += marks[i];
    // }

    // int average = total / 5;
    // char grade;

    // switch (average)
    // {
    // case 0 ... 49:
    //     grade = 'F';
    //     break;
    // case 50 ... 59:
    //     grade = 'E';
    //     break;
    // case 60 ... 69:
    //     grade = 'D';
    //     break;
    // case 70 ... 79:
    //     grade = 'C';
    //     break;
    // case 80 ... 89:
    //     grade = 'B';
    //     break;
    // case 90 ... 100:
    //     grade = 'A';
    //     break;
    
    // default:
    //     printf("An error occured, maybe you put the wrong values? \n");
    //     break;
    // }
    
    // printf("Your average grade is: %c \n " , grade);

    //postlabs

    int num1,num2,num3;
    printf("enter three number: ");
    scanf("%d%d%d",&num1,&num2,&num3);

    if(num1>num2 && num1>num3){
        printf("%d is greater: ",num1);
    }else if (num2>num1 && num2>num3){
        printf("%d is greater: ",num2);
    }else if (num3>num1 && num3>num2){
        printf("%d is greater: ",num3);
    }




    return 0;
}