#include<stdio.h>

int main(){
    int i,j,n,arr[5][5],temp,choice;
    printf("Enter the elements of array:\n");

    for(i=0;i<5;i++){
        for(int j = 0 ; j < 5 ; j++){
            scanf("%d" , arr[i][j]);
        }
    }

    printf("Enter the no. of shifts:\n");
    scanf("%d",&n);
    printf("Enter the direction of shift,1 for right and 0 for left:\n");
    scanf("%d",&choice);

    if(choice==1){
        for(j=0;j<n;j++){
            temp=arr[4];
            for(i=4;i>=0;i--){
                arr[i][j]=arr[i-1][j];

            }
            arr[0][j]=temp;
        }
    }
    else{

        for(j=0;j<n;j++){
            temp=arr[0];
            for(i=1;i<5;i++){
                arr[i-1][j]=arr[i][j];

            }
            arr[4][j]=temp;
        }
    }

    printf("Rotated array is:\n");

    for(i=0;i<5;i++){
        printf("%d",arr[i][j]);
    }

    return 0;
}