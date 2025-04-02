import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadPooling{
    public static void main(String[] args) {
        ExecutorService executor=Executors.newFixedThreadPool(3);
        for(int i=1; i<=5; i++){
            int taskID=i;
            
            executor.execute(()->{
                System.out.println("Task "+taskID+" executed by "+Thread.currentThread().getName());
            });
        }
        executor.shutdown();
    }
}