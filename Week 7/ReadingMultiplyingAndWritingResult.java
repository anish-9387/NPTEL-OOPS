import java.io.*;

public class ReadingMultiplyingAndWritingResult{
    public static void main(String[] args){
        int num1=0, num2=0;

        // Read 2 numbers from input2.txt
        try{
            BufferedReader reader=new BufferedReader(new FileReader("input2.txt"));
            num1=Integer.parseInt(reader.readLine());
            num2=Integer.parseInt(reader.readLine());
            reader.close();
        }
        catch(IOException e){
            System.out.println("Unable to open input file");
            e.printStackTrace();
            return;
        }

        // Multiplying the numbers
        int result=num1*num2;

        // Write the result to output2.txt
        try{
            BufferedWriter writer=new BufferedWriter(new FileWriter("output2.txt"));
            writer.write(Integer.toString(result));
            writer.close();
        }
        catch(IOException e){
            System.out.println("Unable to open output file");
            e.printStackTrace();
        }

        System.out.println("Result written to output2.txt: "+result);
    }
}