class InvalidMarksException extends Exception{
    public InvalidMarksException(String message){
        super(message);
    }
}

class Student{
    private String name;
    private int marks;

    public Student(String name, int marks) throws InvalidMarksException{
        this.name=name;
        setMarks(marks);
    }

    public void setMarks(int marks) throws InvalidMarksException{
        if(marks<0 || marks>100){
            throw new InvalidMarksException("Invalid marks: "+marks+". Marks should be between 0 and 100");
        }
        else{
            this.marks=marks;
        }
    }

    public char getGrade(){
        if(marks>=90){
            return 'A';
        }
        else if(marks>=80){
            return 'B';
        }
        else if(marks>=70){
            return 'C';
        }
        else if(marks>=60){
            return 'D';
        }
        else{
            return 'F';
        }
    }

    public void displayStudentInfo(){
        System.out.println("Student name: "+name);
        System.out.println("Marks: "+marks);
        System.out.println("Grade: "+getGrade());
    }
}

public class GradingManagement_CaseStudy1{
    public static void main(String[] args) {
        try{
            Student student1=new Student("Anshul", 85);
            student1.displayStudentInfo();
            System.out.println();

            Student student2=new Student("Jane Kaliya", 105);
            student2.displayStudentInfo();
        }

        catch(InvalidMarksException e){
            System.out.println("Exception caught: "+e.getMessage());
        }
    }
}