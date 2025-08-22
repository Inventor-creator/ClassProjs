import java.util.Scanner;

public class Exp2{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the name of the student: ");
        String inpName = scanner.nextLine();

        System.out.print("Enter the student id of the student: ");
        int inpStudentId = scanner.nextInt();

        System.out.print("Enter the grade of the student: ");
        int inpGrade = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter the course name of the student: ");
        String inpCourseName = scanner.nextLine();



        Student student = new Student(inpName, inpStudentId , inpCourseName , inpGrade);
        System.out.println("Student1: ");
        student.getStudentInfo();

        System.out.println();

        Student student2 = new Student(student);
        System.out.println("Student2: ");
        student2.getStudentInfo();

        System.out.println();

        System.out.println("Default constructor Student: ");
        Student defaultStudent = new Student();
        defaultStudent.getStudentInfo();


    }
}

class Student{
    String name;
    int studentId;
    String courseName;
    int grade;

    public Student(){
        name = "";
        studentId = -1;
    }

    public Student(String Name , int StudentId, String CourseName , int Grade){
        this.name = Name;
        this.studentId = StudentId;
        this.courseName = CourseName;
        this.grade = Grade;
    }

    public Student(Student s){
        this.name = s.name;
        this.studentId = s.studentId;
        this.courseName = s.courseName;
        this.grade = s.grade;
    }

    public void getStudentInfo(){

        System.out.printf("Student Id: %d \nStudent Name: %s \nCourse Name: %s\nGrade: %d \n" , this.studentId , this.name , this.courseName , this.grade);
    }

}

