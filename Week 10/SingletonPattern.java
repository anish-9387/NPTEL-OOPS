class SingletonPattern{
    private static SingletonPattern instance;

    private SingletonPattern() {}

    public static SingletonPattern getInstance(){
        if(instance==null){
            instance=new SingletonPattern();
        }
        return instance;
    }

    public void displayMessage(){
        System.out.println("Singleton instance!");
    }

    public static void main(String[] args){
        SingletonPattern singleton=SingletonPattern.getInstance();
        singleton.displayMessage();
    }
}