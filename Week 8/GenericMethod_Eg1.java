public class GenericMethod_Eg1{
    // Generic method to print any type of array
    public static <T> void printArray(T[] array){
        for(T element: array){
            System.out.print(element+" ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        Integer[] intArray={1,2,3,4};
        String[] stringArray={"Java","Generics","Example"};

        System.out.print("Integer Array: ");
        printArray(intArray);

        System.out.print("String Array: ");
        printArray(stringArray);
    }
}