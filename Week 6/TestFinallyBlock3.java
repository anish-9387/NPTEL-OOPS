// Program if execution occurs and handled

public class TestFinallyBlock3{
    public static void main(String[] args) {
        try{
            int data=25/0;
            System.out.println(data);
        }
        catch(ArithmeticException e){
            System.out.println(e);
        }
        finally{
            System.out.println("Finally block is always executed");
        }

        System.out.println("Rest of the code");
    }
}