// Two types of exceptions in JAVA- checked (at compile time) and unchecked (at run-time)

// Unchecked Exception example: (Checked at run-time)

public class ArithmException{
    public static void main(String[] args) {
        int a=50/0;
        System.out.println(a);
    }
}