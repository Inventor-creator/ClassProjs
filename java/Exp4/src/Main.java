import java.util.Scanner;

class Student{
    int rollNum;

    public int getRollNumber(){
        return this.rollNum;
    }
    public void putRollNumber(int rollNumber){
        this.rollNum = rollNumber;
    }
}

class Test extends Student{
    int[] marks = new int[3] ;

    public void putMarks(int marks , int subjectId){
        this.marks[subjectId] = marks;
    }


}

interface Sports{
    public void putBonus(int bonus);
    public int getBonus();
}

class Results extends Test implements Sports{
    int bonus = 0;

    public void putBonus(int bonus){
        this.bonus = bonus;
    }

    public int getBonus(){
        return this.bonus;
    }
    public int getMarks(){
        return marks[0] + marks[1] + marks[2]  + bonus;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Results r = new Results();

        System.out.println("Enter rollNum of student: ");
        r.putRollNumber(scanner.nextInt());
        System.out.println("Enter bonus of Student");
        r.putBonus(scanner.nextInt());

        for(int i = 0 ; i < 3 ; i++ ){
            System.out.println("Enter marks for subject "+ (i + 1) + ": ");
            r.putMarks(scanner.nextInt() , i);
        }
        System.out.println("The total marks of student "+ r.getRollNumber()  +" are: "+ r.getMarks() );

    
    }
}
