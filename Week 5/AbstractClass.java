// Abstract class is same as virtual functions in c++

/* 2 ways to achieve abstraction in java:
   --> Abstract class (0 to 100%)
   --> Interface (100%)
*/

abstract class Bike{   // its object cannot be instantiated
    abstract void run();
}

class Honda extends Bike{
    void run(){
        System.out.println("Running safely....");
    }
}

public class AbstractClass{
    public static void main(String[] args) {
        Bike obj=new Honda();
        obj.run();
    }
}