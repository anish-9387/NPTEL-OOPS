// member function --> c++
// method --> java

class Car{
    String brand;
    int year;

    void displayInfo(){
        System.out.println("Car Brand: "+brand);
        System.out.println("Year: "+year);
    }
}

public class Basics_class{  // Main --> driver class
    public static void main(String[] args) {
        Car myCar=new Car();  // Address in c++ <--> Identity hashmap in java

        myCar.brand="Kia";
        myCar.year=2025;

        myCar.displayInfo();
    }    
}