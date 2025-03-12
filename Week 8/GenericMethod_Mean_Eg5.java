public class GenericMethod_Mean_Eg5{
    public static <T extends Number> double mean(T[] numbers){
        double sum=0.0;
        for(T num: numbers){
            sum+=num.doubleValue();
        }
        return sum/numbers.length;
    }

    public static void main(String[] args) {
        Integer[] intNumbers={1,2,3,4,5};
        Double[] doubleNumbers={1.5,2.5,3.5,4.5};

        System.out.println("Mean of int array: "+mean(intNumbers));
        System.out.println("Mean of double array: "+mean(doubleNumbers));
    }
}