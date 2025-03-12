public class GenericMethod_Eg4{
    public static <T> int countOccurrences(T[] array, T element){
        int count=0;
        for(T item: array){
            if(item.equals(element)){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args){
        Integer[] intArray={1,2,3,2,4,2};
        System.out.println("Occurrence of 2: "+countOccurrences(intArray, 2));

        String[] strArray={"apple","banana","apple","cherry"};
        System.out.println("Occurrence of 'apple': "+countOccurrences(strArray, "apple"));
    }
}