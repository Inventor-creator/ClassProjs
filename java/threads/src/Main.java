import java.lang.Thread;
import java.util.ArrayList;
import java.util.Scanner;
//
//class A extends Thread{
//    public void run(){
//        for(int i=1; i<=5;i++){
//            System.out.println("\tThread A: i= "+i);
//        }
//        System.out.println("Exit from Thread A");
//    }
//}
//class B extends Thread{
//    public void run(){
//        for(int j=1; j<=5;j++){
//            System.out.println("\tThread B: j= "+j);
//        }
//        System.out.println("Exit from Thread B");
//    }
//}
//
//class C extends Thread{
//    public void run(){
//        for(int k=1; k<=5;k++){
//            System.out.println("\tThread C: k= "+k);
//        }
//        System.out.println("Exit from Thread C");
//    }
//}
//public class Main {
//    public static void main(String[] args) {
//        new A().start();
//        new B().start();
//        new C().start();
//    }
//}

class Primes extends Thread{
    public ArrayList<Integer> run(Integer n){
        ArrayList<Integer> returnList = new ArrayList<>();
        Boolean flag = false;
        returnList.add(2);
        for(int i= 3 ; i < n ; i++){

            for(int j = 2 ; j < i ; j++){
                if(i % j == 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                returnList.add(i);
                System.out.println("prime: ");
                System.out.println(i);
            }
            flag = false;
        }

        return returnList;
    }
}

class Fibonachi extends Thread{
    public ArrayList<Integer> run(Integer n){
        ArrayList<Integer> returnList = new ArrayList<>();
        Integer prev1 = 0;
        Integer prev2 = 1;
        Integer temp;

        returnList.add(prev1);
        returnList.add(prev2);
        System.out.println("fibo ");
        System.out.println(prev1);
        System.out.println("fibo ");
        System.out.println(prev2);

        for(int i = 2; i < n ; i++){
            temp = prev1;
            prev1 = prev2;
            prev2 = prev2 + temp;
            returnList.add(prev2);
            System.out.println("fibo ");
            System.out.println(prev2);
        }
        return  returnList;
    }
}

public class Main{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Integer tmep = sc.nextInt();
        ArrayList<Integer> primes = new Primes().run(tmep);
        ArrayList<Integer> fib = new Fibonachi().run(tmep);

//        System.out.println("primes: ");
//        for(int i = 0 ; i < primes.toArray().length; i++){
//            System.out.println(primes.get(i));
//        }
//        System.out.println("fibonnachi: ");
//        for(int i = 0 ; i < fib.toArray().length; i++){
//            System.out.println(fib.get(i));
//        }
        sc.close();
    }
}
