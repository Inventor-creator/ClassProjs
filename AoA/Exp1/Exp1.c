#include <stdio.h>


int main() {
   int temp;
   int counter = 0;
   int steps = 0;


   scanf("%d", &temp);


   int elements[temp];
   while(counter < temp){


       scanf("%d", &elements[counter]);
       counter++;
   }


   int temp2 = 0;
   for(int key = 1 ; key < counter ; key++){
       // printf("%d \n" , elements[key]);
       if(elements[key - 1] > elements[key] ){
           for( int j = 0 ; j < key ; j++){
               if(elements[j] >= elements[key]){
                   temp2 = elements[j];
                   elements[j] = elements[key];
                   elements[key] = temp2;
               }
               steps++;
           }
           continue;
       }
       steps++;
   }


   printf("%d\n", steps);


   printf("\n");


   return 0;
}
