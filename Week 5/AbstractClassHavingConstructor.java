abstract class Bike{  // 50% abstraction
    Bike(){  // non-abstracted constructor
        System.out.println("Bike is created");
    }

    abstract void run();  // abstracted method

    void changeGear(){   // non-abstracted method
        System.out.println("Gear changed");
    }
}

class Honda extends Bike{
    void run(){
        System.out.println("Running safely....");
    }
}

public class AbstractClassHavingConstructor{
    public static void main(String[] args) {
        Bike obj=new Honda();
        obj.run();
        obj.changeGear();  // overriden
    }
}