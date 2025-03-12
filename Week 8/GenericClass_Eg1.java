// Template in C++ is same as Generics in Java

public class GenericClass_Eg1<T>{  // Container<T>
    private T value;

    public GenericClass_Eg1(T value){
        this.value=value;
    }

    public T getValue(){
        return value;
    }

    public void setValue(T value){
        this.value=value;
    }

    public static void main(String[] args){
        GenericClass_Eg1<Integer> intContainer=new GenericClass_Eg1<>(123);
        GenericClass_Eg1<String> stringContainer=new GenericClass_Eg1<>("Generics in Java");

        System.out.println("Integer value: "+intContainer.getValue());
        System.out.println("String value: "+stringContainer.getValue());
    }
}