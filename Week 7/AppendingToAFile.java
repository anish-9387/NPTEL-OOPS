import java.io.FileWriter;
import java.io.IOException;

public class AppendingToAFile{
    public static void main(String[] args) {
        try{
            FileWriter writer=new FileWriter("example2.txt",true);  // append mode
            writer.write("Appended line.\n");
            System.out.println("Appended successfully");
            writer.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}