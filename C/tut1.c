#include <stdio.h>

int main(){
    int x,y;
    scanf("%d%d" , &x , &y );
    printf("%d %d %d\n" , x + y , x * y , x % y);
    printf("%d %d %d\n" , x && y , x || y , x ^ y);
    printf("%d %d %d\n" ,x & y , x | y , !x );

    x > y ? printf("x is greater\n"):printf("y is greater\n");

    if(x >= y) printf("x is greater");


    return 0;

}