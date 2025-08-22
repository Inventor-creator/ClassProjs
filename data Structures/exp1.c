#include <stdio.h>


struct Student
{


   char name[20];
   int rollNo;


};




int main(){


   struct Student studentArr[10];


   //insert into last position
   int counter = 0;
   int action = 0;


   while(counter < 10){


       printf("1> Add new Student \n2> Delete Student \n3> Search Student \n4> Display List Of Students \n");
       scanf("%d" , &action);
       action--;


       switch (action)
       {
           case 0:
               printf("Adding new student\n");


               printf("Enter Student Name: ");
               scanf("%s", &studentArr[counter].name);


               printf("Enter Student rollNo: ");
               scanf("%d", &studentArr[counter].rollNo);
               counter++;
               break;
           case 1:
               printf("Deleting from last position \n");
               struct Student stu;
               studentArr[counter] =  stu;


               counter--;
               break;
           case 2:
               int rollNoSearch = 0;
               printf("Enter a roll no u want to search: ");
               scanf("%d" , &rollNoSearch);
               int flag = 0;
               for(int i = 0; i < counter ; i++){
                   if(studentArr[i].rollNo == rollNoSearch){


                       printf(" %s %d \n" , studentArr[i].name , studentArr[i].rollNo);


                   }
               }
              


               break;
           case 3:
               for(int i = 0; i < counter ; i ++){


                       printf(" %s %d \n" , studentArr[i].name , studentArr[i].rollNo);


               }
               break;
           default:
               printf("Wrong input called");
               break;
       }




      
   }


   for(int i = 0; i < 10 ; i ++){
                  
       printf(" %s %d \n" , studentArr[i].name , studentArr[i].rollNo);
   }   


   return 0;
}
