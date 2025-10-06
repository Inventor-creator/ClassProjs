package MyPackage;

public class Checker {
    public Checker(){
        
    }

    public void displayPrime(int number){

        for(int i = 2 ; i < number ; i++){
            if(number % i == 0){
                System.out.println("Is not a prime number");
                return;
            }
        }
        System.out.println("Is a prime");
    
    }

    public void displayEvenOdd(int number){
        if(number % 2 == 0){
            System.out.println("Number is Even");
        }
        else{
            System.out.println("Number is odd");
        }

    }

}
