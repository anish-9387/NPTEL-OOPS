class Shape{
    private String colour;

    public Shape(String colour){   // constructor
        this.colour=colour;
    }

    public void setColour(String colour){  // method
        this.colour=colour;
    }

    public String getColour(){
        return colour;
    }

    public double calculateArea(){
        return 0;
    }
}

class Circle extends Shape{
    private double radius;

    public Circle(String colour, double radius){
        super(colour);   // calling Shape constructor
        this.radius=radius;
    }

    @Override
    public double calculateArea(){
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape{
    private double length;
    private double width;

    public Rectangle(String colour, double length, double width){
        super(colour);
        this.length=length;
        this.width=width;
    }

    @Override
    public double calculateArea(){
        return length*width;
    }
}

public class HeirarchicalInheritance{
    public static void main(String[] args){
        Circle circle=new Circle("Red", 5.0);
        System.out.println("Circle colour: "+circle.getColour());
        System.out.println("Circle Area: "+circle.calculateArea());

        Rectangle rectangle=new Rectangle("Blue", 4.0, 6.0);
        System.out.println("Rectangle colour: "+rectangle.getColour());
        System.out.println("Rectangle Area: "+rectangle.calculateArea());
    }
}