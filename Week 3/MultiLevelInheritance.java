class Class1{
    public void method1(){
        System.out.println("Base class method");
    }
}

class Class2 extends Class1{
    public void method2(){
        System.out.println("Inside Class2, method2");
    }
}

class Class3 extends Class2{
    public void method2(){
        System.out.println("Inside Class3, method2");
    }
}

public class MultiLevelInheritance{
    public static void main(String[] args){
        Class3 c=new Class3();
        c.method1();
        c.method2();  // overriding Class2 and printing Class3
    }
}