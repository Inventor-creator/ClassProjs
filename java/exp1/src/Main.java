import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice = 4;
        System.out.println("Enter your name");
        Account bank = new Account(scanner.nextLine());
        do{

            System.out.println("Enter your Choice:\n1>Deposit Amount\n2>Withdraw amount\n3>Display Amount\n4>Exit");

            choice = scanner.nextInt();
            switch (choice){
                case 1:
                    bank.deposit(scanner);
                    break;
                case 2:
                    bank.withdraw(scanner);
                    break;
                case 3:
                    bank.display();
                    break;
                case 4:
                    System.out.println("Thanks for using my program");
                    break;
                default:
                    System.out.println("Not ");
                    break;

            }

        }while(choice != 4 );


        scanner.close();
    }

}


class Account{
    public int amount;
    public String name;
    public Account(String n){
        System.out.println("New Account Opened");
        this.name = n;
        this.amount = 0;
    }

    public void deposit(Scanner scanner){

        System.out.println("Enter a value to deposit");
        int depVal = scanner.nextInt();
        amount += depVal;
        System.out.println("Deposited value");

    }

    public void withdraw(Scanner scanner){

        System.out.println("Enter a value to withdraw");
        int widVal = scanner.nextInt();

        if(amount > widVal){
            amount -= widVal;
            System.out.println("Withdrew successfully");
        }
        else{
            System.out.println("Input a value smaller than your bank account ");

        }

    }

    public void display(){
	   System.out.printf("%s : %d\n" , this.name , this.amount);
    }
}
