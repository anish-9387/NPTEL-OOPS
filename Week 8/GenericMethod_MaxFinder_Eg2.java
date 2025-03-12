public class GenericMethod_MaxFinder_Eg2{
    public static <T extends Comparable<T>> T findMax(T a, T b, T c){
        T max=a;
        if(b.compareTo(max)>0)  max=b;
        if(c.compareTo(max)>0)  max=c;
        return max;
    }

    public static void main(String[] args){
        System.out.println("Max of 3,5,4: "+findMax(3, 5, 4));
        System.out.println("Max of A,Z,M: "+findMax("A", "Z", "M"));
    }
}