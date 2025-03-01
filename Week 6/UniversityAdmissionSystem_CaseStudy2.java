class InvalidAgeException extends Exception{
    public InvalidAgeException(String message){
        super(message);
    }
}

class InsufficientScoreException extends Exception{
    public InsufficientScoreException(String message){
        super(message);
    }
}

class Student{
    private String name;
    private int age, score;

    public Student(String name, int age, int score) throws InvalidAgeException, InsufficientScoreException{
        this.name=name;
        setAge(age);
        setScore(score);
    }

    public void setAge(int age) throws InvalidAgeException{
        if(age<18){
            throw new InvalidAgeException("Age must be 18 or above for admission");
        }
        this.age=age;
    }

    public void setScore(int score) throws InsufficientScoreException{
        if(score<60){
            throw new InsufficientScoreException("Score must be 60 or above for admission");
        }
        this.score=score;
    }

    public void displayStudentInfo(){
        System.out.println("Student name: "+name);
        System.out.println("Age: "+age);
        System.out.println("Score: "+score);
        System.out.println("Status: Admitted");
    }
}

public class UniversityAdmissionSystem_CaseStudy2{
    public static void main(String[] args) {
        try{
            Student student1=new Student("Kishore", 19, 75);
            student1.displayStudentInfo();
            System.out.println();

            Student student2=new Student("Pradeep", 17, 85);
            student2.displayStudentInfo();
        }
        catch(InvalidAgeException e){
            System.out.println("Admission Failed: "+e.getMessage());
        }
        catch(InsufficientScoreException e){
            System.out.println("Admission Failed: "+e.getMessage());
        }

        try{
            Student student3=new Student("Anshul", 20, 55);
            student3.displayStudentInfo();
        }
        catch(InvalidAgeException e){
            System.out.println("Admission Failed: "+e.getMessage());
        }
        catch(InsufficientScoreException e){
            System.out.println("Admission Failed: "+e.getMessage());
        }
    }
}