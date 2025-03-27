import java.util.ArrayList;
import java.util.List;

interface Investor{
    void update(String stock, double price);
}

class IndividualInvestor implements Investor{
    private String name;

    public IndividualInvestor(String name){
        this.name=name;
    }

    // @Override
    public void update(String stock, double price){
        System.out.println(name+" notified - "+stock+" Price: $"+price);
    }
}

class StockExchange{
    private List<Investor> investors=new ArrayList<>();
    private String stock;
    private double price;

    public void attach(Investor investor){
        investors.add(investor);
    }

    public void setStockPrice(String stock, double price){
        this.stock=stock;
        this.price=price;
        notifyInvestors();
    }

    private void notifyInvestors(){
        for(Investor investor : investors){
            investor.update(stock, price);
        }
    }
}

public class StockMarket_ObserverPattern{
    public static void main(String[] args){
        StockExchange exchange=new StockExchange();
        Investor alice=new IndividualInvestor("Alice");
        Investor bob=new IndividualInvestor("Bob");

        exchange.attach(alice);
        exchange.attach(bob);

        exchange.setStockPrice("AAPL", 150.0);
        exchange.setStockPrice("GOOGL", 2800.0);
    }
}