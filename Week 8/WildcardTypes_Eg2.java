import java.util.List;

public class WildcardTypes_Eg2{
    public static void printList(List<? extends Number> list){
        for(Number n: list){
            System.out.print(n+" ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        List<Integer> intList=List.of(1,2,3,4);
        List<Double> doubleList=List.of(1.1,2.2,3.3);

        System.out.print("Integer List: ");
        printList(intList);
        
        System.out.print("Double List: ");
        printList(doubleList);
    }
}