public class ArrayIndexOutOfBoundException{
    public static void main(String[] args){
        int a[]=new int[5];
        a[10]=50;  // no index 10 present
        System.out.println(a[10]);
    }
}