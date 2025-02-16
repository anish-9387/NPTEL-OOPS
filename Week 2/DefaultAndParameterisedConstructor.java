class Perimeter{
    int length, breadth;

    Perimeter(){  // default constructor
        length=0;
        breadth=0;
    }

    Perimeter(int x, int y){
        length=x;
        breadth=y;
    }

    void cal_perimeter(){
        int peri;
        peri=2*(length+breadth);
        System.out.println("\nThe perimeter of the rectangle is: "+peri);
    }
}

public class DefaultAndParameterisedConstructor {
    public static void main(String[] args) {
        Perimeter p1=new Perimeter();  // default constructor
        Perimeter p2=new Perimeter(25,100);  // parameterised constructor

        p1.cal_perimeter();
        p2.cal_perimeter();
    }
}