import java.io.*;
import java.net.*;

public class CreatingSimpleServer{
    public static void main(String[] args) throws IOException{
        ServerSocket serverSocket=new ServerSocket(8080);
        System.out.println("Server listening on port 8080");

        Socket clientSocket=serverSocket.accept();
        PrintWriter out=new PrintWriter(clientSocket.getOutputStream(),true);
        out.println("Hello, Client!");

        clientSocket.close();
        serverSocket.close();
    }
}