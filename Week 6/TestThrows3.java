// Program if the exception occurs


import java.io.*;

class M{
    void method() throws IOException{
        throw new IOException("Device error");
    }
}

public class TestThrows3{
    public static void main(String[] args) throws IOException{
        M m=new M();
        m.method();

        System.out.println("Normal flow...");
    }
}