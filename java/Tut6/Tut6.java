import MyPackage.Checker;
import java.util.Scanner;

public class Tut6 {
    public static void main(String[] args) {
        Checker check = new Checker();

        System.out.println("Enter a number: ");
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        check.displayPrime(num);
        check.displayEvenOdd(num);
    }    
}
