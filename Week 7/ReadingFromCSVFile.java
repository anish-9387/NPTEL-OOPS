import java.io.*;

public class ReadingFromCSVFile{
    public static void main(String[] args){
        try(BufferedReader reader=new BufferedReader(new FileReader("readFromCSVFile2.csv"))){
            String line;
            while((line=reader.readLine()) != null){
                String[] cells=line.split(",");
                for(String cell:cells){
                    System.out.print(cell+"\t");
                }
                System.out.println();
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}