#include <stdio.h>

int main(){
    // int x,y;
    // scanf("%d%d" , &x , &y );
    // printf("%d %d %d\n" , x + y , x * y , x % y);
    // printf("%d %d %d\n" , x && y , x || y , x ^ y);
    // printf("%d %d %d\n" ,x & y , x | y , !x );

    // x > y ? printf("x is greater\n"):printf("y is greater\n");

    int x,y,z;
    scanf("%d%d%d" , &x , &y , &z );


    if(x > y){
        if (x > z){
            printf("x is the greatest");
        }
        else{
            printf("z is the greatest ");

        }
    
    }
    else if (y > x)
    {
        if (y > z){
            printf("y is the greatest");
        }
        else{
            printf("z is the greatest");

        }
    }
    else{
        if (z > x){
            printf("z is the greatest");
        }
        else{
            printf("x is the greatest");

        } 
    }
    

    return 0;

}