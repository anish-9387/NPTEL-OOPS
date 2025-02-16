class Person{
    void message(){
        System.out.println("Welcome");
    }
}

class Student16 extends Person{
    void message(){
        System.out.println("Welcome to Java");
    }

    void display(){
        message();  // invokes current class method
        super.message();   // invokes the parent class method
    }
}

public class SuperKeyword3 {
    public static void main(String[] args) {
        Student16 s=new Student16();
        s.display();
    }
}