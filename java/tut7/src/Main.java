import java.util.*;

public class Main{
    public static void main(String[] args){

        ArrayList<Double> a = new ArrayList<>();
        ArrayList<String> a2 = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();
        TreeSet<Integer> tree = new TreeSet<>();
        HashMap<Integer , String> hmap = new HashMap<>();
        TreeMap<Integer , String > tmap = new TreeMap<>();


        a.add(1.0);
        a.add(2.0);
        a.add(3.0);

        a2.add("yay");
        a2.add("yay2");
        a2.add("yay3");

        set.add(2);
        set.add(1);
        set.add(1);

        tree.add(3);
        tree.add(1);
        tree.add(2);

        hmap.put(2 , "bye");
        hmap.put(1 , "hello");
        hmap.put(1,"bruh");

        tmap.put(3 , "apple");
        tmap.put(1 , "somefruit");
        tmap.put(2 , "some2f");

        System.out.println(a);
        System.out.println(a2);
        System.out.println("first ele = " + a.get(0));
        a.remove(2);
        a.set(1,10.0);
        System.out.println(a);
        System.out.println(set);
        System.out.println(tree);
        System.out.println(hmap);
        System.out.println(tmap);

    }
}