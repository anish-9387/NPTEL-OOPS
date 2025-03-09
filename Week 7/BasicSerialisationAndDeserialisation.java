import java.io.*;

class MyClass implements Serializable{
    private static final long serialVersionUID=1L;
    int data;

    public MyClass(int data){
        this.data=data;
    }

    // Method to serialise the object
    public void serialise(String filename){
        try(ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(filename))){
            oos.writeObject(this);
            System.out.println("Data serialised to " + filename);
        }
        catch(IOException e){
            System.err.println("Error during serialisation: " + e.getMessage());
        }
    }

    // Method to deserialise the object
    public static MyClass deserialise(String filename){
        try(ObjectInputStream ois=new ObjectInputStream(new FileInputStream(filename))){
            return (MyClass) ois.readObject();
        }
        catch(IOException | ClassNotFoundException e){
            System.err.println("Error during deserialisation: " + e.getMessage());
            return null;
        }
    }
}

public class BasicSerialisationAndDeserialisation{
    public static void main(String[] args) {
        String filename="serialised_data.ser";

        MyClass obj=new MyClass(42);
        System.out.println("Original data: " + obj.data);
        obj.serialise(filename);

        obj.data=0;
        System.out.println("Data after reset: " + obj.data);

        MyClass deserialisedObj=MyClass.deserialise(filename);
        if(deserialisedObj!=null){
            System.out.println("Data after deserialisation: " + deserialisedObj.data);
        }
    }
}