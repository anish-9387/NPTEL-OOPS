interface Notification{
    void notifyUser();
}

class EmailNotification implements Notification{
    public void notifyUser(){
        System.out.println("Sending Email Notification");
    }
}

class SMSNotification implements Notification{
    public void notifyUser(){
        System.out.println("Sending SMS Notification");
    }
}

class NotificationFactory{
    public static Notification createNotification(String type){
        if(type.equalsIgnoreCase("email")){
            return new EmailNotification();
        }

        if(type.equalsIgnoreCase("sms")){
            return new SMSNotification();
        }
        return null;
    }
}

public class FactoryPatternImplementation2{
    public static void main(String[] args){
        Notification notification=NotificationFactory.createNotification("EMAIL");
        if(notification!=null)  notification.notifyUser();
    }
}