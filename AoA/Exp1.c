#include <stdio.h>

int main() {
    int temp;
    int counter = 0;

    printf("Enter the number of elements in the unsorted list: ");
    scanf("%d", &temp);

    int elements[temp];
    while(counter < temp){
        printf("Enter a number: ");
        scanf("%d", &elements[counter]);
        counter++;
    }

    int temp2 = 0;
    for(int key = 1 ; key < counter ; key++){
        // printf("%d \n" , elements[key]);
        if(elements[key - 1] > key ){
            for( int j = 0 ; j < key ; j++){
                if(elements[j] >= elements[key]){
                    temp2 = elements[j];
                    elements[j] = elements[key];
                    elements[key] = temp2;

                }

            }
        }
    }

    for(int i = 0 ; i < counter ; i++){
        printf("%d ", elements[i]);
    }
    printf("\n");

    return 0;
}
