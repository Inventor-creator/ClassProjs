//import java.util.Scanner;
//
//public class Main{
//    public static void main(String[] args){
////        String str = "hello java world";
////        System.out.println("length: " + str.length());
////
////        System.out.println("char at index 3: " + str.charAt(3));
////        System.out.println("substring 6:8 " + str.substring(6,8) );
////
////        System.out.println("concatenated string: " + str.concat("!!!"));
////
////        System.out.println("index of 'java': " + str.indexOf("java"));
////        System.out.println("Equals to str2?: " + str.equals("Hello world"));
////        System.out.println("EqualsIgnoreCase? " + str.trim().equalsIgnoreCase("HELLO JAVA WORLD"));
////        System.out.println("to upper: " + str.toUpperCase() );
//
////        StringBuffer sb = new StringBuffer("hello");
////
////        sb.append(" world");
////
////        sb.insert(5 , "java " );
////
////        System.out.println(sb.toString());
////
////        String s = "hello";
////        System.out.println(s.concat(" world"));
////        System.out.println("String: " + s);
////
////        StringBuffer sb = new StringBuffer("hello");
////        sb.append(" world");
////        System.out.println("String buffer: " + sb );
//
//
//
//    }
//}

import java.util.Scanner;

public class Main {
    private static StringBuilder text = new StringBuilder();


    public static void appendText(String str) {
        text.append(str);
    }


    public static void insertText(int position, String str) {
        if (position < 0 || position > text.length()) {
            System.out.println("Invalid position!");
            return;
        }
        text.insert(position, str);
    }


    public static void replaceText(int start, int end, String str) {
        if (start < 0 || end > text.length() || start > end) {
            System.out.println("Invalid range!");
            return;
        }
        text.replace(start, end, str);
    }


    public static void deleteText(int start, int end) {
        if (start < 0 || end > text.length() || start > end) {
            System.out.println("Invalid range!");
            return;
        }
        text.delete(start, end);
    }


    public static void displayText() {
        System.out.println("Current Text: \"" + text.toString() + "\"");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Simple Text Editor ---");
            System.out.println("1. Append Text");
            System.out.println("2. Insert Text");
            System.out.println("3. Replace Text");
            System.out.println("4. Delete Text");
            System.out.println("5. Display Text");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter text to append: ");
                    appendText(sc.nextLine());
                    break;

                case 2:
                    System.out.print("Enter position to insert: ");
                    int pos = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter text to insert: ");
                    insertText(pos, sc.nextLine());
                    break;

                case 3:
                    System.out.print("Enter start index: ");
                    int start = sc.nextInt();
                    System.out.print("Enter end index: ");
                    int end = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter replacement text: ");
                    replaceText(start, end, sc.nextLine());
                    break;

                case 4:
                    System.out.print("Enter start index: ");
                    int delStart = sc.nextInt();
                    System.out.print("Enter end index: ");
                    int delEnd = sc.nextInt();
                    deleteText(delStart, delEnd);
                    break;

                case 5:
                    displayText();
                    break;

                case 6:
                    System.out.println("bye");
                    break;

                default:
                    System.out.println("Invalid choice, please try again");
            }
        } while (choice != 6);

        sc.close();
    }
}

