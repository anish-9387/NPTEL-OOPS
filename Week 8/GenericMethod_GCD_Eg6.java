class GenericMethod_GCD_Eg6{
    @SuppressWarnings("unchecked")  // for line 12
    public static <T extends Number> T gcd(T a, T b){
        long num1=a.longValue();
        long num2=b.longValue();

        while(num2!=0){
            long temp=num2;
            num2=num1%num2;
            num1=temp;
        }
        return (T)Long.valueOf(num1);
    }

    public static void main(String[] args){
        Integer a=56, b=98;
        Long x=12345677899L, y=987654321L;

        System.out.println("GCD of 56 and 98: "+gcd(a, b));
        System.out.println("GCD of 123456789 and 987654321: "+gcd(x, y));
    }
}