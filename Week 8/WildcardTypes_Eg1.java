import java.util.List;

public class WildcardTypes_Eg1{
    public static void printNumbers(List<? extends Number> list){
        for(Number n: list){
            System.out.println(n);
        }
    }
}

// ?: Unbounded wildcard (any type)
// ? extends T: Upper-bounded wildcard, any subtype of T
// ? super T: Lower-bounded wildcard, any supertype of T