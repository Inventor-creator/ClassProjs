import MathPackage.MyMath;
import java.util.Scanner;

public class Exp5{
    public static void main(String[] args) {
        MyMath myMath = new MyMath();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the value of x: ");
        int number = scanner.nextInt();
        System.out.println("Enter power of x: ");
        int power = scanner.nextInt();

        System.out.println("The answer is: " + myMath.power(number,power));

        System.out.println("Enter the x value in the series sum: ");
        int x = scanner.nextInt();
        System.out.println("Enter the number of times the series is supposed to sum: ");
        int n = scanner.nextInt();
        System.out.println("The sum of the series is: " + myMath.getSum(x , n));

    }
}