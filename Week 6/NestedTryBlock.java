public class NestedTryBlock{
    public static void main(String[] args){
        int c=100;
        try{
            try{
                System.out.println("Going to divide");
                @SuppressWarnings("unused")
                int b=39/0;
            }

            catch(ArithmeticException e){
                System.out.println(e);
            }

            try{
                int a[]=new int[5];
                a[5]=4;
            }

            catch(ArrayIndexOutOfBoundsException e){
                System.out.println(e);
            }

            System.out.println("Other statement");
            c=c/0;
        }

        catch(Exception e){
            System.out.println("Handled");
        }

        System.out.println("Normal flow");
    }
}