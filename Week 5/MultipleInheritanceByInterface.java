interface Printable{
    void print();
}

interface Showable{
    void show();
}

class B implements Printable, Showable{
    public void print(){
        System.out.println("Hi, I am learning");
    }

    public void show(){
        System.out.println("Multiple Inheritance through java interface");
    }
}

public class MultipleInheritanceByInterface{
    public static void main(String[] args) {
        B obj=new B();
        obj.print();
        obj.show();
    }
}