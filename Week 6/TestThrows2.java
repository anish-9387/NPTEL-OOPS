// Program if the exception doesn't occurs

import java.io.*;

class M{
    void method() throws IOException{
        System.out.println("Device operation performed");
    }
}

public class TestThrows2{
    public static void main(String[] args) throws IOException{
        M m=new M();
        m.method();

        System.out.println("Normal flow...");
    }
}