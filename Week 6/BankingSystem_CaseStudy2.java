class InsufficientFundsException extends Exception{
    public InsufficientFundsException(String message){
        super(message);
    }
}

class BankAccount{
    private double balance;
    
    public BankAccount(double initialBalance){
        this.balance=initialBalance;
    }

    public void withdraw(double amount) throws InsufficientFundsException{
        if(amount>balance){
            throw new InsufficientFundsException("Insufficient balance. Cannot withdraw: Rs."+amount);
        }
        balance-=amount;
        System.out.println("Withdrawn successfully. Remaining balance: Rs."+balance);
    }

    public double getBalance(){
        return balance;
    }
}

public class BankingSystem_CaseStudy2{
    public static void main(String[] args) {
        BankAccount account=new BankAccount(1000.00);
        double withdrawAmount=1200.00;

        try{
            System.out.println("Attempting to withdraw Rs."+withdrawAmount);
            account.withdraw(withdrawAmount);
        }
        catch(InsufficientFundsException e){
            System.out.println("Error: e.getMessage()");
        }
        finally{
            System.out.println("Transaction completed. Current balance: Rs."+account.getBalance());
        }
    }
}