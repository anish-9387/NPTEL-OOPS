import java.util.Scanner;

class Distance{
    int feet, inches;

    void setValues(int f, int i){
        feet=f;
        inches=i;
    }

    Distance add(Distance d){
        Distance result=new Distance();

        result.inches=inches+d.inches;
        result.feet=feet+d.feet+(result.inches/12);
        result.inches%=12;
        
        return result;
    }

    void display(){
        System.out.println(feet+" feet "+inches+" inches");
    }
}

public class AddingDistances {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        Distance d1=new Distance();
        Distance d2=new Distance();
        Distance result;

        System.out.print("Enter feet and inches for the 1st distance: ");
        int feet1=sc.nextInt();
        int inches1=sc.nextInt();
        d1.setValues(feet1, inches1);

        System.out.print("Enter the feet and inches for the 2nd distance: ");
        int feet2=sc.nextInt();
        int inches2=sc.nextInt();
        d2.setValues(feet2, inches2);

        result=d1.add(d2);
        System.out.print("The sum of the two distances is: ");
        result.display();

        sc.close();
    }
}