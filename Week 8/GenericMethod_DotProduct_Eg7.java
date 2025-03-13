public class GenericMethod_DotProduct_Eg7{
    public static <T extends Number> double dotProduct(T[] vectorA, T[] vectorB){
        if(vectorA.length!=vectorB.length){
            throw new IllegalArgumentException("Vectors must be of the same length");
        }

        double sum=0.0;
        for(int i=0; i<vectorA.length; i++){
            sum+=vectorA[i].doubleValue()*vectorB[i].doubleValue();
        }
        return sum;
    }

    public static void main(String[] args) {
        Integer[] vectorA={1,2,3};
        Integer[] vectorB={4,5,6};

        Double[] vectorC={1.1,2.2,3.3};
        Double[] vectorD={4.4,5.5,6.6};

        System.out.println("Dot product (int vectors): "+dotProduct(vectorA, vectorB));
        System.out.println("Dot product (double vectors): "+dotProduct(vectorC, vectorD));
    }
}