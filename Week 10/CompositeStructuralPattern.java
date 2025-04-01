import java.util.ArrayList;
import java.util.List;

abstract class FileSystem{  // Component
    abstract void display();
}

class File extends FileSystem{  // Leaf
    private String name;
    public File(String name){
        this.name=name;
    }

    public void display(){
        System.out.println(name);
    }
}

class Folder extends FileSystem{  // Composite
    private List<FileSystem> chilren=new ArrayList<>();

    public void add(FileSystem child){
        chilren.add(child);
    }

    public void display(){
        for(FileSystem child : chilren){
            child.display();
        }
    }
}

public class CompositeStructuralPattern{  // Client
    public static void main(String[] args) {
        Folder root=new Folder();
        root.add(new File("file1.txt"));
        root.add(new File("file2.txt"));
        root.display();
    }
}