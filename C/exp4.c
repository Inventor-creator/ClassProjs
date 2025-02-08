#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("16014224088 Arya Patil\n");

    //Q1

    // int number;
    // printf("enter the number of elements you want in array: ");
    // scanf("%d" , &number);
    
    // int array[number];  

    // for(int i = 0; i < number; i++){

    //     scanf("%d" , &array[i]);
        
    // }

  

    // int length = sizeof(array) / sizeof(array[0]);
    
    // for(int i = length -1 ; i >= 0 ; i--){
    //     printf("%d " , array[i]);
    // }
    // printf("\n");

    //Q2

    // int number;
    // printf("enter the number of elements you want in array: ");
    // scanf("%d" , &number);

    // int array[number];  
    // int length = sizeof(array) / sizeof(array[0]);

    // for(int i = 0; i < number; i++){

    //     scanf("%d" , &array[i]);
        
    // }
    
    // int temp;

    // //bubble sort ascending
    // for(int i = 0 ; i < length ; i++){
    //     int r = 1 ;
    //     int l = 0;
    //     while (r < length)
    //     {

    //         if(array[l] >= array[r]){
    //             temp = array[r];
    //             array[r] = array[l];
    //             array[l] = temp;
    //         }
            
            
            
    //         l++;
    //         r++;
    //     }
        
    // }

    //bubble sort descending
    // for(int i = 0 ; i < length ; i++){
    //     int r = 1 ;
    //     int l = 0;
    //     while (r < length)
    //     {

    //         if(array[l] <= array[r]){
    //             temp = array[r];
    //             array[r] = array[l];
    //             array[l] = temp;
    //         }
            
            
            
    //         l++;
    //         r++;
    //     }
        
    // }

    // for(int j = 0; j < number ; j++){
    //     printf("%d ",array[j]);
        
    // }


    //Q3

    // int n, i, j, count = 0;
    
   
    // printf("Enter the number of elements in the array: ");
    // scanf("%d", &n);
    
    // int arr[n], visited[n];

    
    // for(i = 0; i < n; i++) {
    //     visited[i] = 0;
    // }
    
    
    // printf("Enter the elements of the array:\n");
    // for(i = 0; i < n; i++) {
    //     scanf("%d", &arr[i]);
    // }
    
    
    // for(i = 0; i < n; i++) {
    //     if (visited[i] == 1) {
    //         continue;  
    //     }
    //     int duplicateFound = 0;
    //     for(j = i + 1; j < n; j++) {
    //         if(arr[i] == arr[j]) {
    //             visited[j] = 1;  
    //             duplicateFound = 1;
    //         }
    //     }
    //     if (duplicateFound) {
    //         count++;  
    //     }
    // }
    
    
    // printf("Total number of duplicate elements: %d\n", count);
    

    //Postlabs

    //Q1

    // int number;
    // printf("enter the number of elements you want in array: ");
    // scanf("%d" , &number);

    // int array[number];  
    // int length = sizeof(array) / sizeof(array[0]);

    // for(int i = 0; i < number; i++){

    //     scanf("%d" , &array[i]);
        
    // }   

    // int maxx = array[0];
    // int minn = array[0];

    // for(int i = 0 ; i < number ; i++){
    //     if(maxx <= array[i]){
    //         maxx = array[i];
    //     }
    //     if(minn >= array[i]){
    //         minn = array[i];
    //     }
    // }

    // printf("The minimum is: %d \n The maximum is: %d\n", minn , maxx);


    //Q2

    // int matrix1[2][2] = {{1,5},
    //                     {1,2}};

    // int matrix2[2][2] = {{1,2},
    //                     {5,2}};

    // int rows = sizeof(matrix1) / sizeof(matrix1[0]);
    // int columns = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);

    // int newMatix [rows][columns];

    // for(int i = 0; i < rows; i++){
    //     for(int j = 0; j < columns ; j++){
    //         newMatix[i][j] = matrix1[i][j] +  matrix2[i][j];
    //     }
    // }

    // for(int i = 0; i < rows; i++){
    //     for(int j = 0; j < columns ; j++){
    //         printf("%d " , newMatix[i][j]);
    //     } 
    //     printf("\n");
    // }




    return 0;
}






