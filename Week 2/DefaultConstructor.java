class Bike1{
    Bike1(){   // deafult constructor
        System.out.println("Bike is created");
    }
}

public class DefaultConstructor {
    public static void main(String[] args) {
        Bike1 b=new Bike1();
        System.out.println(b); // address==identity hashmap
    }
}
