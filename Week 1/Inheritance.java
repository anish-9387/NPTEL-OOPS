class Vehicle{  // superclass == base class
    String brand;

    void showBrand(){   // method
        System.out.println("Brand: "+brand);
    }
}

class Car extends Vehicle{  // subclass == derived class
    String model;

    void showModel(){
        System.out.println("Model: "+model);
    }
}

public class Inheritance{
    public static void main(String[] args) {
        Car myCar=new Car();

        myCar.brand="Toyota";
        myCar.model="Corolla";

        myCar.showBrand();
        myCar.showModel();
    }
}