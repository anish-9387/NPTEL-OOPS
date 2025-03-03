import java.io.FileWriter;
import java.io.IOException;

public class WritingInAFile{
    public static void main(String[] args) {
        try{
            FileWriter myWriter=new FileWriter("example2.txt");
            myWriter.write("Writing into the Java file\n");
            myWriter.write("Welcome to file handling in Java");
            System.out.println("Written in the file successfully!!!");
            myWriter.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}