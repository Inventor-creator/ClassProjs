//import java.util.*;
//
//public class Main{
//    public static void main(String[] args){
//
//        ArrayList<Double> a = new ArrayList<>();
//        ArrayList<String> a2 = new ArrayList<>();
//        HashSet<Integer> set = new HashSet<>();
//        TreeSet<Integer> tree = new TreeSet<>();
//        HashMap<Integer , String> hmap = new HashMap<>();
//        TreeMap<Integer , String > tmap = new TreeMap<>();
//
//
//        a.add(1.0);
//        a.add(2.0);
//        a.add(3.0);
//
//        a2.add("yay");
//        a2.add("yay2");
//        a2.add("yay3");
//
//        set.add(2);
//        set.add(1);
//        set.add(1);
//
//        tree.add(3);
//        tree.add(1);
//        tree.add(2);
//
//        hmap.put(2 , "bye");
//        hmap.put(1 , "hello");
//        hmap.put(1,"bruh");
//
//        tmap.put(3 , "apple");
//        tmap.put(1 , "somefruit");
//        tmap.put(2 , "some2f");
//
//        System.out.println(a);
//        System.out.println(a2);
//        System.out.println("first ele = " + a.get(0));
//        a.remove(2);
//        a.set(1,10.0);
//        System.out.println(a);
//        System.out.println(set);
//        System.out.println(tree);
//        System.out.println(hmap);
//        System.out.println(tmap);
//
//    }
//}

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> products = new ArrayList<>();


        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("1. Print the collection");
            System.out.println("2. Insert an element at the first position");
            System.out.println("3. Retrieve an element at specified index");
            System.out.println("4. Update an element");
            System.out.println("5. Remove the third element");
            System.out.println("6. Search for an element");
            System.out.println("7. Sort products");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // Consume newline

            switch(choice) {
                case 1:
                    System.out.println("Products: " + products);
                    break;
                case 2:
                    System.out.print("Enter product name to insert at first position: ");
                    String firstProd = sc.nextLine();
                    products.add(0, firstProd);
                    System.out.println("Inserted successfully.");
                    break;
                case 3:
                    System.out.print("Enter the index to retrieve: ");
                    int idx = sc.nextInt();
                    if (idx >= 0 && idx < products.size()) {
                        System.out.println("Element at index " + idx + ": " + products.get(idx));
                    } else {
                        System.out.println("Invalid index.");
                    }
                    break;
                case 4:
                    System.out.print("Enter the index to update: ");
                    int updIdx = sc.nextInt();
                    sc.nextLine(); // Consume newline
                    if (updIdx >= 0 && updIdx < products.size()) {
                        System.out.print("Enter new product name: ");
                        String updProd = sc.nextLine();
                        products.set(updIdx, updProd);
                        System.out.println("Updated successfully.");
                    } else {
                        System.out.println("Invalid index.");
                    }
                    break;
                case 5:
                    if (products.size() >= 3) {
                        products.remove(2);  // Remove third element (index 2)
                        System.out.println("Removed the third element.");
                    } else {
                        System.out.println("Less than 3 elements present.");
                    }
                    break;
                case 6:
                    System.out.print("Enter product name to search: ");
                    String searchProd = sc.nextLine();
                    if (products.contains(searchProd)) {
                        System.out.println("Product found at index: " + products.indexOf(searchProd));
                    } else {
                        System.out.println("Product not found.");
                    }
                    break;
                case 7:
                    Collections.sort(products);
                    System.out.println("Sorted products: " + products);
                    break;
                case 8:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 8);

        sc.close();
    }
}
