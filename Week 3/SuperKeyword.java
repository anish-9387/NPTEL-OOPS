class Vehicle{
    Vehicle(){
        System.out.println("Vehicle is created");
    }

    int speed=50;
}

class Bike3 extends Vehicle{
    int speed=100;
    void display(){
        System.out.println(speed);
    }    
}

class Bike4 extends Vehicle{
    int speed=150;
    void display(){
        System.out.println(super.speed);
    }
}

class Bike5 extends Vehicle{
    Bike5(){
        super(); // will invoke parent class constructor
        System.out.println("Bike is created");
    }
}

public class SuperKeyword{
    public static void main(String[] args){       
        // Bike3 b=new Bike3();
        // b.display();
        
        // Bike4 c=new Bike4();  // super enabled super class' variable to print the speed
        // c.display();

        @SuppressWarnings("unused")
        Bike5 d=new Bike5();
    }
}