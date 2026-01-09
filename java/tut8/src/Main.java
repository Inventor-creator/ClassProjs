import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {

        HashMap<Integer, String> map = new HashMap<>();
        map.put(1, "Apple");
        map.put(2, "Banana");
        map.put(3, "Cherry");
        System.out.println("Map after adding elements: " + map);


        int size = map.size();
        System.out.println("Size of map: " + size);


        HashMap<Integer, String> mapCopy = new HashMap<>();
        mapCopy.putAll(map);
        System.out.println("Copied map: " + mapCopy);


        if (map.isEmpty()) {
            System.out.println("Map is empty");
        } else {
            System.out.println("Map is not empty");
        }


        int testKey = 2;
        if (map.containsKey(testKey)) {
            System.out.println("Map contains key: " + testKey);
        } else {
            System.out.println("Map does not contain key: " + testKey);
        }
    }
}
