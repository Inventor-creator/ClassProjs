#include <stdio.h>
#include <stdlib.h>

int main(){

    // int i = 0;
    // int num ;
    // int bitss[10];

    // printf("Enter a number ");
    // scanf("%d" , &num);

    // while(num >= 0){
    //     bitss[i] = num % 2; 
    //     num = num/ 2;
    //     i++;
    // }

    // for(int i = 0; i < 11 ; i++){
    //     printf("%d \n" , bitss[i]);
    // }

    // int l = 0;
    // int length;
    // int mid;

    // int target ;
    

    // printf("Enter the length of the array you want: ");
    // scanf("%d" , &length);

    // int array[length];
    // int r = length-1;

    
    // printf("Enter the elements of array \n");
    // for( int i =0; i < length ; i++){
    //     scanf("%d" , &array[i]);
    // }

    // printf("Enter the target number: ");
    // scanf("%d" , &target);

    // while(r >= l){
    //     mid = (l + r) / 2;
    //     if ( array[mid] == target){
    //         printf("Element found, at index: %d \n" , mid);
    //         break;
    //     }
    //     else if( array[mid]<= target){
    //         l = mid;
    //     }
    //     else if( array[mid] >= target){
    //         r = mid;
    //     }
    //     if((r - l) == 1){
    //         printf("Num not found \n");
    //         break;
    //     }

    //     if(target == array[r]){
    //         printf("The number is found is: %d\n" , r);
    //     }

    // }


    int maxStudentId ;
    int MaxMarks = 0;
    
    int students, subjects;
    
    printf("Enter the number of students ");
    scanf("%d", &students);
    printf("Enter the number of subjects ");
    scanf("%d", &subjects);

    int database[students][subjects];

    float avgSubs[subjects];

    for(int i = 0 ; i < students; i++){
        printf("Enter Marks of Student %d: \n", i + 1);
        for(int j = 0 ; j < subjects; j++){
            printf("\tEnter Marks of Subject %d: ", j + 1);
            scanf("%d" , &database[i][j]);
        }
    }

    for(int i = 0 ; i < subjects; i++){
        float temp = 0;
        for(int j = 0 ; j < students; j++){
            temp += database[j][i];
        }
        avgSubs[i] = temp / students;
    }

    for(int i = 0 ; i < subjects; i++){
        printf("The average marks for subject %d are %.2f\n",i + 1 , avgSubs[i]);
    }
    
    printf("student %d has the max marks\n", maxStudentId + 1);

    return 0;
}