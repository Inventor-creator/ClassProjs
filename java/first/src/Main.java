import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        int x  = scanner.nextInt();
//        int y = scanner.nextInt();
//        int z = scanner.nextInt();
//
        int day = scanner.nextInt();

        switch(day){
            case 1:
                System.out.println("Sunday");
                break;
            case 2:
                System.out.println("Monday");
                break;
            case 3:
                System.out.println("Tuesday");
                break;
            case 4:
                System.out.println("Wednesday");
                break;
            case 5:
                System.out.println("Thursday");
                break;
            case 6:
                System.out.println("Friday");
                break;
            case 7:
                System.out.println("Saturday");
                break;
            default:
                System.out.println("Invalid Inp");
        }

//        Calculator calc = new Calculator();
//
//        calc.addition(x,y);
//        calc.substraction(x,y);
//        calc.multiplication(x,y);
//        calc.division(x,y);

//        if( x > y && x > z ){
//            System.out.printf("%d is the greatest" , x);
//        }
//        else if( y > x && y > z ){
//            System.out.printf("%d is the greatest" , y);
//        }
//        else{
//            System.out.printf("%d is the greatest" , z);
//        }

        scanner.close();
    }
}

interface calculation{
public void addition(int x , int y);
public void division(int x , int y);
public void multiplication(int x , int y);
public void substraction(int x , int y);

}

class Calculator implements calculation {

    public Calculator(){
        System.out.println("calc created");
    }

    public void addition(int x , int y){
        System.out.println("addition is " +(x + y));
    }
    public void division(int x , int y){
        System.out.println("division is " +(x / y));
    }
    public void multiplication(int x , int y){
        System.out.println("multiplication is " +(x * y));
    }
    public void substraction(int x , int y){
        System.out.println("substraction is " + (x - y));
    }


}