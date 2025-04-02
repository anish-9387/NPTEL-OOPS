import java.util.concurrent.Semaphore;

public class UsingSemaphores{
    public static void main(String[] args) {
        Semaphore semaphore=new Semaphore(3);

        Runnable worker=()->{
            try{
                semaphore.acquire();
                System.out.println(Thread.currentThread().getName()+" is running");
                Thread.sleep(2000);
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
            finally{
                semaphore.release();
            }
        };

        for(int i=0; i<5; i++){
            new Thread(worker).start();
        }
    }
}