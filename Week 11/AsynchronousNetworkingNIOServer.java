// NIO= New Input Output

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.*;

public class AsynchronousNetworkingNIOServer{
    public static void main(String[] args) throws IOException{
        Selector selector=Selector.open();
        ServerSocketChannel serverSocket=ServerSocketChannel.open();
        serverSocket.bind(new java.net.InetSocketAddress(12345));
        serverSocket.configureBlocking(false);
        serverSocket.register(selector,SelectionKey.OP_ACCEPT);

        System.out.println("Server is listening...");

        while(true){
            selector.select();
            for(SelectionKey key : selector.selectedKeys()){
                if(key.isAcceptable()){
                    SocketChannel client=serverSocket.accept();
                    client.configureBlocking(false);
                    client.register(selector,SelectionKey.OP_READ);
                    System.out.println("Client connected");
                }
                else if(key.isReadable()){
                    SocketChannel client=(SocketChannel)key.channel();
                    ByteBuffer buffer=ByteBuffer.allocate(256);
                    client.read(buffer);
                    System.out.println("Recieved: "+new String(buffer.array()).trim());
                }
            }
            selector.selectedKeys().clear();
        }
    }
}