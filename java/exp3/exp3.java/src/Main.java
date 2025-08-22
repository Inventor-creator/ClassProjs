
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Salary employee = new Salary();
        employee.getSalary();
        employee.getDepartment();
        System.out.println("The HRA is: " + employee.HRA);
        System.out.println("The DA is: " + employee.DA);
        System.out.println("The grade pay is: " + employee.gradePay);

    }
}

class Employee{
    Scanner eScanner = new Scanner(System.in);
    int employeeId;
    String name;
    double HRA;
    double gradePay;
    double DA;
    String deptName;
    int bonus;
    int basicPay;


    public Employee(){
        System.out.println("Enter the employee id of employee");
        employeeId = eScanner.nextInt();
        System.out.println("Enter the bonus of employee");
        bonus = eScanner.nextInt();
        eScanner.nextLine();
        System.out.println("Enter the name of employee");
        name = eScanner.nextLine();
        System.out.println("Enter the deptName of employee");
        deptName = eScanner.nextLine();
        System.out.println("Enter the basic Pay of employee");
        basicPay = eScanner.nextInt();

        DA = basicPay * 0.55;
        gradePay = DA * 0.25;
        HRA = basicPay * 0.4;

    }

}

class Department extends Employee{

    public Department(){
        super();
    }
    public void getDepartment(){

        System.out.println("The department name of the employee is: "+super.deptName);
    }



}

class Salary extends Department{
    int numDays;
    Scanner scanner = new Scanner(System.in);
    public Salary(){
        super();
        System.out.println("Enter the num of days attended by employee");
        numDays = scanner.nextInt();

    }
    public void getSalary(){
        System.out.println("The salary of the employee is: ");
        System.out.println((super.basicPay / 30) * numDays + super.bonus );
    }

}


