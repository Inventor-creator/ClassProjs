#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    printf("16014224088 Arya Patil\n");

    // //Q1
    
    // char inp[20];

    // printf("Enter the string you want to check: ");
    // gets(inp, 20, stdin);

    // int length = sizeof(inp) / sizeof(inp[0]);

    // int vovelNum = 0;
    // int consonantNum = 0;

    // for (int i = 0; i < length; i++){
        
    //     if((inp[i] <= 'z' && inp[i] >= 'a') || (inp[i] <= 'Z' && inp[i] >= 'A')){
    //         switch (inp[i])
    //         {

    //             case 'a':
    //                 vovelNum++;
    //                 break;
    //             case 'e':
    //                 vovelNum++;
    //                 break;
    //             case 'i':
    //                 vovelNum++;
    //                 break;
                
    //             case 'o':
    //                 vovelNum++;
    //                 break;
                
                // case 'u':
                //     vovelNum++;
                //     break;
                
                
                // default:
                //     consonantNum++;
                //     break;
                
    //         }
    //     }
        
        
    // }

    // printf("The total number of vovels in the string provided are: %d , The consonants are: %d\n", vovelNum, consonantNum);


    
    // Q2

    // char studentName[20];
    // char student2Name[20];
    // char studentGrade[5];

    // char newStdNameStr[20];

    // printf("Enter student name: ");
    // fgets(studentName , 20 , stdin);

    // printf("Enter student grade: ");
    // //string copied to another variable 
    // strcpy(newStdNameStr , studentName);
    // printf("The name copied in to a new string is: %s\n" , newStdNameStr);

    // //adding the prompt to the end of the string 
    // printf("The concatenated string is: %s" , strncat(newStdNameStr , "-Excelent student" , 17));
    // printf("\n");


    // printf("Enter Second student name: ");
    // scanf("%s" , &student2Name);

    // //comparing lexographically

    // int result = strcmp(studentName, student2Name);

    // if (result > 0) {
    //     printf("%s is lexicographically greater than %s\n", studentName, student2Name);
    // } 
    // else if(result < 0) {
    //     printf("%s is lexicographically greater than %s\n", student2Name, studentName);
    // } 
    // else{
    //     printf("Both names are lexicographically equal\n");
    // }

    // //finding substring
    // char substring[20] = "Ary";
    // char *result2; 
    // result2 = strstr(studentName , substring);

    // if(result2 ){
    //     printf("%ld\n" , result2 - studentName);
    // }

    // char character;

    // printf("Enter a character to search in the grade: ");
    // scanf(" %c", &character);
    // char *charPos = strchr(studentGrade, character);
    // if (charPos) {
    //     printf("Character found at position: %ld\n", charPos - studentGrade);
    // } else {
    //     printf("Character not found.\n");
    // }

    //   printf("Tokenized grade components:\n");
    // char *token = strtok(studentGrade, " ");
    // while (token) {
    //     printf("%s\n", token);
    //     token = strtok(NULL, " ");
    // }


    return 0;
}