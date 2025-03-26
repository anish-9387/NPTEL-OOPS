interface Shape{  // Abstract Product
    void draw();
}

class Circle implements Shape{  // Concrete Products
    public void draw(){
        System.out.println("Drawing circle");
    }
}

class Square implements Shape{
    public void draw(){
        System.out.println("Drawing square");
    }
}

class ShapeFactory{
    public static Shape createShape(String type){
        if(type.equalsIgnoreCase("circle")){
            return new Circle();
        }

        if(type.equalsIgnoreCase("square")){
            return new Square();
        }
        return null;
    }
}

public class FactoryPatternImplementation{
    public static void main(String[] args){
        Shape shape=ShapeFactory.createShape("Circle");
        if(shape!=null)  shape.draw();
    }
}