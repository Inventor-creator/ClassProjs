#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    printf("16014224088 Arya Patil\n");


    // //Q1
    char vovels[] = "aeiouAEIOU";
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    char inp[20]; 

    printf("Enter the string you want to check: ");
    fgets(inp , 20 , stdin);

    int length = sizeof(inp) / sizeof(inp[0]);

    int vovelNum = -5;
    int consonantNum = 0;

    for(int i = 0 ; i < length ; i++){
        
        char *pointerC = strchr(consonants,(char)inp[i]);
        char *pointerV = strchr(vovels,(char)inp[i]);

        if(pointerV != NULL){
            vovelNum++;
        }
        else if(pointerC != NULL){
            consonantNum++;
        }

    }

    printf("The total number of vovels in the string provided are: %d , The consonants are: %d\n" , vovelNum,consonantNum);

    //Q2

    // char studentName[20];
    // char student2Name[20];
    // char studentGrade;

    // char newStdNameStr[20];

    // printf("Enter student name: ");
    // fgets(studentName , 20 , stdin);

    // printf("Enter student grade: ");
    // scanf("%c" , &studentGrade);

    // strcpy(newStdNameStr , studentName);
    // printf("The name copied in to a new string is: %s\n" , newStdNameStr);

    // printf("The concatenated string is: %s" , strncat(studentName , "-Excelent student" , 17));
    // printf("\n");

    // printf("Enter Second student name: ");
    // scanf("%s" , &student2Name);
      



    return 0;
}