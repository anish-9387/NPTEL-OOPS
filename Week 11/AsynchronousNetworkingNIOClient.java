import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.*;

public class AsynchronousNetworkingNIOClient{
    public static void main(String[] args) {
        try{
            SocketChannel client=SocketChannel.open(new InetSocketAddress("localhost",12345));
            client.configureBlocking(false);

            System.out.println("Connected to the server");

            String message="Hello, NIO Server!";
            ByteBuffer buffer=ByteBuffer.wrap(message.getBytes());
            client.write(buffer);
            System.out.println("Message sent: "+message);

            ByteBuffer readBuffer=ByteBuffer.allocate(256);
            while(true){
                int bytesRead=client.read(readBuffer);
                if(bytesRead>0){
                    System.out.println("Recieved: "+new String(readBuffer.array(),0,bytesRead).trim());
                    break;
                }
            }

            client.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}