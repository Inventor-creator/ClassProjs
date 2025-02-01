#include <stdio.h>
#include <math.h>

//Q1

void Q1(){
    float side1 , side2 , side3;
    printf("Enter sides of triangle ");
    scanf("%f%f%f" , &side1 , &side2 , & side3);
   
    if( (side1 + side2 > side3) || (side2 + side3 > side1) || (side3 + side1 > side2)){
        

        if((side1 == side2 && side2 != side3)) {
            printf("It is a isoceles Triangle\n");
        }
        else if (side1 == side2 && side2 == side3)
        {
            printf("It is an equilateral triangle\n");
        }
        else if (side1 != side2 && side2 != side3 && side1 != side3)
        {
            printf("it is a scalene triangle\n");
        }
        
        

    }
    else{
        printf("Not a Triangle! \n");
    }


}

// void Q2(){
//     float x1,x2,y1,y2,r1 , r2;

//     printf("Enter x of 1st circle: ");
//     scanf("%f" , &x1 );
//     printf("Enter y of 1st circle: ");
//     scanf("%f" , &y1 );
//     printf("Enter radius of 1st circle: ");
//     scanf("%f" , &r1 );

//     printf("Enter x of 2nd circle: ");
//     scanf("%f" , &x2 );
//     printf("Enter y of 2nd circle: ");
//     scanf("%f" , &x1 );
//     printf("Enter radius of 2st circle: ");
//     scanf("%f" , &r1 );

//     float d ;
    
//     d = pow( pow(x1 - x2 , 2) + pow(y1 - y2 , 2), 0.5);

//     if(d < r1+ r2 ){
//         printf("Circles are intersecting\n");
//     }
//     else if(d > r1+ r2){
//         printf("circles are not intersecting\n");
//     }
//     else if(d == r1+ r2){
//         printf("circles are touching each other\n");
//     }
//     else{
//         printf("Idk what is happening \n");
        
//     }


// }


int main(){
    Q1();
    return 0;
}

