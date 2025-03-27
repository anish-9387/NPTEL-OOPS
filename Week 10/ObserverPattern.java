import java.util.ArrayList;
import java.util.List;

class Subject{
    private List<Observer> observers=new ArrayList<>();

    public void attach(Observer observer){
        observers.add(observer);
    }

    public void notifyObservers(String message){
        for(Observer observer : observers){
            observer.update(message);
        }
    }
}

interface Observer{
    void update(String message);
}

class ConcreteObserver implements Observer{
    public void update(String message){
        System.out.println("Observer recieved: "+message);
    }
}

public class ObserverPattern{
    public static void main(String[] args){
        Subject subject=new Subject();
        Observer observer1=new ConcreteObserver();
        Observer observer2=new ConcreteObserver();

        subject.attach(observer1);
        subject.attach(observer2);

        subject.notifyObservers("Hello Observers!");
    }
}