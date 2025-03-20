#include <stdio.h>  
#include <stdlib.h>

long long int facto(int n){
    long long int fact = 1;
    for(int i = 1 ; i <= n ; i++){
        fact *= i;
        printf("%lld \n" , fact);
    }
    return fact;
}

void xchg(int* a , int* b){
        
    int t = *a;
    *a = *b;
    *b = t;
}

int recurFact(int n){

    if (n == 0) return 1;

    return n * recurFact(n-1);
}


int main(){
    
    int n;
    printf("Enter a number: ");
    scanf("%d" , &n);
    // printf("The factorial is %lld \n" , facto(n));
    printf("The recursive factorial is %d \n" ,  recurFact(n));

    // void(*p)(int * ,int *);
    // p = &xchg;
    // int x , y;
    // int* px = &x;
    // int* py = &y;
    // printf("Enter two numbers x and y: ");
    // scanf("%d%d", &x , &y );
    // (*p)(px , py );
    // printf("The two numbers are x:%d y:%d\n", x , y );
    
    
    
    return 0;
}

