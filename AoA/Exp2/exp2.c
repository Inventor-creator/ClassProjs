#include <stdio.h>

int steps = 0;

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int makePartitions(int arr[] , int low, int high){

    int pivot = arr[high];

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        steps++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }

    steps++;
    swap(&arr[i + 1], &arr[high]);
    return i + 1;

}

void quickSort(int* arr , int low, int high){

    if(low >= high){
        return;
    }

    int pivot = makePartitions(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);

}

int main(){
    int N;
    scanf("%d", &N);
    int temp[N];


    for(int i =0 ; i< N;i++){
        scanf("%d", &temp[i]);
    }

    quickSort(temp, 0, N - 1);

    printf("%d\n", steps);
    // printf("sorted list: \n");
    // for(int i =0 ; i< N;i++){

    //     printf("%d ", temp[i]);

    // }
    // printf("\n");

    return 0;
}
