import java.io.*;

public class ReadingCharByChar{
    public static void main(String[] args) {
        try{
            // Opening file for reading char-by-char
            System.out.println("Reading character by character:");
            try(FileReader fr=new FileReader("example2.txt")){
                int i;
                while((i=fr.read()) != -1){
                    char c=(char)i;

                    if(c=='\n'){
                        System.out.print("\\n");
                    }
                    else if(c==' '){
                        System.out.print("_");
                    }
                    else{
                        System.out.print(c);
                    }
                }
            }

            // Opening file for reading char-by-char
            System.out.println("\n\nReading line by line:");
            try(BufferedReader br=new BufferedReader(new FileReader("example2.txt"))){
                String line;
                int lineNumber=1;
                while((line=br.readLine()) != null){
                    System.out.println("Line " + lineNumber++ + ": " +line);
                }
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}