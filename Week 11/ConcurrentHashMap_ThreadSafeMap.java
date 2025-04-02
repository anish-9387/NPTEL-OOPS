import java.util.concurrent.ConcurrentHashMap;

public class ConcurrentHashMap_ThreadSafeMap{
    public static void main(String[] args){
        ConcurrentHashMap<Integer, String> map=new ConcurrentHashMap<>();
        map.put(1,"A");
        map.put(2,"B");

        map.forEach((key, value)->System.out.println(key + ": " + value));
    }
}