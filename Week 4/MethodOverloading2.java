class Student{
    private String name;

    public Student(String name){
        this.name=name;
    }

    public void calculateGrade(double percentage){
        if(percentage>=90){
            System.out.println(name+" has secured Grade A");
        }
        else if(percentage>=80){
            System.out.println(name+" has secured Grade B");
        }
        else if(percentage>=70){
            System.out.println(name+" has secured Grade C");
        }
        else if(percentage>=60){
            System.out.println(name+" has secured Grade D");
        }
        else{
            System.out.println(name+" has failed");
        }
    }

    public void calculateGrade(char letterGrade){
        switch (letterGrade) {
            case 'A':
                System.out.println(name+" has excellent performance with Grade A");
                break;
            case 'B':
                System.out.println(name+" has good performance with Grade B");
                break;
            case 'C':
                System.out.println(name+" has average performance with Grade C");
                break;
            case 'D':
                System.out.println(name+" has poor performance with Grade D");
                break;        
            default:
                System.out.println(name+" has failed");
        }
    }

    public void calculateGrade(float gpa){
        if(gpa>=4.0){
            System.out.println(name+" has secured Grade A");
        }
        else if(gpa>=3.0){
            System.out.println(name+" has secured Grade B");
        }
        else if(gpa>=2.0){
            System.out.println(name+" has secured Grade C");
        }
        else if(gpa>=1.0){
            System.out.println(name+" has secured Grade D");
        }
        else{
            System.out.println(name+" has failed");
        }
    }
}

public class MethodOverloading2 {
    public static void main(String[] args) {
        Student s=new Student("Ravi Ashwin");

        s.calculateGrade(85.5);
        s.calculateGrade('B');
        s.calculateGrade(3.7f);
    }
}