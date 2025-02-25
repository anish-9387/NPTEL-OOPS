interface printable{  // 100% abstraction
    void print();
}

class A implements printable{
    public void print(){
        System.out.println("Learning interface");
    }
}

public class Interface{
    public static void main(String[] args) {
        A obj=new A();
        obj.print();
    }
}