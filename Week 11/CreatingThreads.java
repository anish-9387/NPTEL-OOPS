class MyThreads extends Thread{
    public void run(){
        System.out.println("Thread running...");
    }
}

public class CreatingThreads{
    public static void main(String[] args) {
        MyThreads thread=new MyThreads();
        thread.start();  // starts the thread and calls run()
    }
}