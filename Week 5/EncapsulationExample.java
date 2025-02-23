class Animal{
    private int age;

    public int getAge(){
        return age;
    }

    public void setAge(int age){
        this.age=age;
    }
}

class EncapsulationExample{
    public static void main(String[] args) {
        Animal a1= new Animal();
        a1.setAge(18);
        System.out.println("Animal's age is: "+a1.getAge());
    }
}