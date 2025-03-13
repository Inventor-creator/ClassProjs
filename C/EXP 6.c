#include <stdio.h>

float mean(int array[] , int length){

    float sum = 0;

    
    

    for(int i = 0; i < length ; i++){
        
        sum += array[i];

    }

    return sum / length;



}

float median(int array[], int length){



    if(length % 2 == 0){
        float temp = (float)array[length / 2 - 1] + (float)array[length / 2];
        
        float temp2 = temp / 2;
        return temp2 ;
    }
    else{
        return array[length/ 2 ];
    }

}

int mode(int array[], int length){
    int keyArr[length];
    int freqArr[length];
    int counter = 0;

    for(int i = 0 ; i < length ; i++){
        freqArr[i] = 0;
        keyArr[i] = 0;
    }


    for(int i = 0 ; i < length ; i++){
        //check the main array
        for(int j = 0 ; j < length ; j++){
            //check keyArr 
            if(keyArr[j] == array[i]){
                freqArr[j]++; 
              
                break;
            }
            

            //make a key if not exists
            if(j == length-1){
                keyArr[counter] = array[i];
                freqArr[counter] = 1;
               
                counter++;
            }
            
        }
    }
    

    int maxIndex = 0;
    int maxx = 0;
    for(int i = 0 ; i < length ; i++){
        if(freqArr[i] > maxx ){
            maxIndex = i;
            maxx = freqArr[i];
            
        }
    } 
  
    return keyArr[maxIndex];

}

void multiplyMatrix(){
    int row1= 0;
    int col1 = 0;
    int row2= 0;
    int col2 = 0;

    int temp;


    printf("Enter the no of rows of the first Matrix: ");
    scanf("%d" , &row1);
    printf("Enter the no of columns of the first Matrix: ");
    scanf("%d" , &col1);

    printf("Enter the no of rows of the second Matrix: ");
    scanf("%d" , &row2);
    printf("Enter the no of columns of the second Matrix: ");
    scanf("%d" , &col2);

    

    if(col1 != row2){
        printf("Matrix cannot be multiplied \n");
        
    }
    else{
        
        //initialize matrices
        int mat1[row1][row2];
        int mat2[row2][col2];

        //taking inputs 

        //first matrice
        printf("Input for first Matrix: \n");
        for(int i = 0 ; i < row1; i++){
            for(int j = 0 ; j < col1 ; j++){
                printf("\trow %d element no %d: " , i+1 , j+1);
                scanf("%d" , &mat1[i][j]);
            }
        }
        //second Matrix
        printf("Input for second Matrix: \n");
        for(int i = 0 ; i < row2; i++){
            for(int j = 0 ; j < col2 ; j++){
                printf("\trow %d element no %d: " , i+1 , j+1);
                scanf("%d" , &mat2[i][j]);
            }
        }

        //multiply

        int multArr[row1][col2];

        for(int i = 0 ; i < row1 ; i++){
            
            for(int j = 0 ; j < col2 ; j++){
                temp = 0;
                for(int k = 0; k < row2 ; k++){
                    temp += mat1[i][k] * mat2[k][j];
                
                }

                multArr[i][j] = temp;
            }

        }

        printf("\n");
        printf("The Multiplied matrix is: \n");

        //Print Matrix for debugging
        for(int i = 0 ; i < row1; i++){
            for(int j = 0 ; j < col2 ; j++){
                printf("%4d " , multArr[i][j]);
            }
            printf("\n");
            
        }
        // for(int i = 0 ; i < row1; i++){
        //     for(int j = 0 ; j < row2 ; j++){
        //         printf("%d \n" , mat2[i][j]);
        //     }
        // }
    }

}


int main(){

    printf("Arya Patil 16014224088\n");

    //Write a C program to find the mean, 
    //median and mode of an array of numbers 
    //using a user-defined function.

    // int inpArr[] = {1,2,3,4,5,5,5,6,6,6,6,7,7,5,5,5,7,7,7};
    // int length = sizeof(inpArr) / sizeof(inpArr[0]);


    // float means = mean(inpArr , length);
    // float medians = median(inpArr , length);
    // int modes = mode(inpArr , length);

    // printf("The mean is:%.2f \n",means);
    // printf("The median is:%.2f \n",medians);
    // printf("The mode is:%d\n",modes);


    //q2

    multiplyMatrix();
   
    

    return 0;
}