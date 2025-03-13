public class BoundedTypes_Eg1{
    public<T extends Number> double add(T a, T b){
        return a.doubleValue()+b.doubleValue();
    }
}

// Accepts any subclass of Number