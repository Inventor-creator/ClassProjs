#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int same(char s1[] , char s2[]){

    int lenchar1 = strlen(s1);
    int lenchar2 = strlen(s2);

    if(lenchar1 != lenchar2){
        return 1;
    }

    for (int i = 0 ; i < lenchar1 ; i++){
        if(s1[i] != s2[i]){
            return 1;
        }
    }

    return 0;
}

int main(){

    
    // char s1[25];
    // printf("Enter a string: ");
    // fgets(s1 , 25 , stdin);

    // int i = strlen(s1);

    // printf("The length of the string is %d \n" , i - 1);

    char s1[25] , s2[25];
    printf("Enter string 1: ");
    fgets(s1 , 25 , stdin);

    printf("Enter string 2: ");
    fgets(s2 , 25 , stdin);

    if(!same(s1 , s2 )){
        printf("Same  \n");
    }
    else{
        printf("Different  \n");
    }

    return 0;
}