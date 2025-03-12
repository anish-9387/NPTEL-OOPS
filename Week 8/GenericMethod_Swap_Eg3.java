import java.util.Arrays;

public class GenericMethod_Swap_Eg3{
    public static <T> void swap(T[] array, int index1, int index2){
        T temp=array[index1];
        array[index1]=array[index2];
        array[index2]=temp;
    }

    public static void main(String[] args){
        Integer[] intArray={1,2,3,4};
        swap(intArray, 0, 3);
        System.out.println("Swapped Integer Array: "+Arrays.toString(intArray));

        String[] strArray={"A","B","C","D"};
        swap(strArray, 1, 2);
        System.out.println("Swapped String Array: "+Arrays.toString(strArray));
    }
}