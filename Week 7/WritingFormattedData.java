import java.io.FileWriter;
import java.io.IOException;

public class WritingFormattedData{
    public static void main(String[] args) {
        try{
            FileWriter writer=new FileWriter("formattedDataInJava.txt");
            writer.write(String.format("Value: %.2f\n", 123.456));
            writer.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}