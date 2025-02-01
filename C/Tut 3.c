#include <stdio.h>

int main(){
    int number;
    printf("enter the number of elements you want in array: ");
    scanf("%d" , &number);

    int array[number];

    int sum  = 0 ;
    int max = 0;
    

    for(int i = 0; i < number; i++){

        scanf("%d" , &array[i]);

        sum = sum + array[i];

        if(array[i] > max){
            max = array[i];
        }
        
    }

    printf("Your array is: [ ");
    for(int i = 0 ; i < number ; i++){
        printf(" %d ," , array[i]);
    }
    printf("]\n");

    float avg = sum / number;
    printf("The sum of the elements is: %d\n" , sum);
    printf("The avg of your array is: %.4f\n" , avg);
    printf("The max of the array is: %d\n" , max);

    return 0;
}



