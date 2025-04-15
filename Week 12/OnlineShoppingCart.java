import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;

abstract class Product{
    private String name;
    private double price;

    public Product(String name, double price){
        if(price<0){
            throw new IllegalArgumentException("Price cannot be negative");
        }
        this.name=name;
        this.price=price;
    }

    public String getName(){
        return name;
    }

    public double getPrice(){
        return price;
    }

    public abstract double calculatePrice();  // Includes discounts and taxes
}

class Electronics extends Product{
    public Electronics(String name, double price){
        super(name,price);
    }

    @Override
    public double calculatePrice(){
        return getPrice()*1.18;  // 18% GST
    }
}

class Clothing extends Product{
    public Clothing(String name, double price){
        super(name,price);
    }

    @Override
    public double calculatePrice(){
        return getPrice()*0.90;  // 10% discount
    }
}

class Cart{
    private ArrayList<Product> products;
    private double discount=0.0;

    public Cart(){
        products=new ArrayList<>();
    }

    public void addProduct(Product product){
        if(product==null){
            throw new NullPointerException("Cannot add null product");
        }
        products.add(product);
    }

    public void removeProduct(Product product){
        if(!products.remove(product)){
            throw new IllegalArgumentException("Product not found in the cart");
        }
    }

    public ArrayList<Product> getProducts(){
        return products;
    }

    public void applyCoupon(String code){
        if(code.equals("SAVE10")){
            discount=0.10;
        }
        else{
            System.out.println("Invalid coupon code: "+code);
        }
    }

    public double calculateTotal(){
        double total=0;
        for(Product product : products){
            total+=product.calculatePrice();
        }
        return total*(1-discount);
    }
}

class Order{
    private Cart cart;

    public Order(Cart cart){
        this.cart=cart;
    }

    public void placeOrder(){
        System.out.println("Order summary:");
        for(Product product : cart.getProducts()){
            System.out.println(product.getName()+" - $"+product.calculatePrice());
        }
        System.out.println("Total: $"+cart.calculateTotal());
    }

    public void saveOrder(String filename){
        try(FileWriter writer=new FileWriter(filename)){
            for(Product product : cart.getProducts()){
                writer.write(product.getName()+" -$"+product.calculatePrice()+"\n");
            }
            writer.write("Total: $"+cart.calculateTotal());
        }
        catch(IOException e){
            System.out.println("Error saving order: "+e.getMessage());
        }
    }
}

public class OnlineShoppingCart{
    public static void main(String[] args) {
        Cart cart=new Cart();

        try{
            // Test 1: Add valid products
            System.out.println("Adding valid products...");
            cart.addProduct(new Electronics("Laptop", 1000));
            cart.addProduct(new Clothing("T-Shirt", 50));
            System.out.println("Products added successfully\n");

            // Test 2: Validate price calculations
            System.out.println("Validating price calculations...");
            for(Product product : cart.getProducts()){
                System.out.println(product.getName()+" - Calculated Price: $"+product.calculatePrice());
            }
            System.out.println();

            // Test 3: Handle invalid product additions
            try{
                System.out.println("Attempting to add a null product...");
                cart.addProduct(null);
            }
            catch(NullPointerException e){
                System.out.println("Caught exception: "+e.getMessage());
            }
            System.out.println();

            // Test 4: Handle invalid product removal
            try{
                System.out.println("Attempting to remove a non-existent product...");
                cart.removeProduct(new Electronics("Phone", 800));
            }
            catch(IllegalArgumentException e){
                System.out.println("Caught exception: "+e.getMessage());
            }
            System.out.println();

            // Test 5: Apply valid and invalid coupon codes
            System.out.println("Applying valid coupon...");
            cart.applyCoupon("SAVE10");
            System.out.println("Coupon applied. Total after discount: $"+cart.calculateTotal());
            System.out.println("Applying invalid coupon...");
            cart.applyCoupon("INVALIDCODE");
            System.out.println();

            // Test 6: Confirm correct order summary
            System.out.println("Placing order...");
            Order order=new Order(cart);
            order.placeOrder();

            // Save the order to a file
            System.out.println("\nSaving order to file...");
            order.saveOrder("order.txt");
            System.out.println("Order saved successfully");
        }
        catch(Exception e){
            System.out.println("Error: "+e.getMessage());
        }
    }
}