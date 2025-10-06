import java.util.Scanner;

class NoMatching extends Exception{
    public NoMatching(){
        System.out.println("Entered string isnt 'somaiya'");
    }
}

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string: ");
        try{
            if(!scanner.nextLine().equals("Somaiya")){
                throw new NoMatching();
            }
            else{
                System.out.println("String entered is Somaiya");
            }
        } catch (NoMatching e) {
            throw new RuntimeException(e);
        }
    }
}1