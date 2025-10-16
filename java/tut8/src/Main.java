import java.util.Arrays;
import java.util.List;

public class Main{
    public static void main(String[] args){
        List<String> names = Arrays.asList("someone" , "sometwo" , "somethree","n1");
        List<String> result = names.stream().filter(name-> name.startsWith("some"))
                .map(String::toLowerCase)
                .toList();
        System.out.println(result);

        

    }
}