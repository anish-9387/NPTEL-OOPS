import java.io.*;
import java.util.Formatter;

public class WritingFormattedData2{
    public static void main(String[] args){
        try{
            BufferedWriter writer=new BufferedWriter(new FileWriter("formattedDataInJava2.txt"));
            Formatter formatter=new Formatter(writer);
            formatter.format("%-20s %10s%n", "Name", "Score");
            formatter.format("%-20s %10d%n", "Alice", 95);
            formatter.format("%-20s %10d%n", "Bob", 87);
            formatter.format("%-20s %10d%n", "Charlie", 78);
            formatter.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}