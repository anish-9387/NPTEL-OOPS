class BankAccount{
    protected String accountHolderName;
    protected double balance;

    public BankAccount(String accountHolderName, double balance){
        this.accountHolderName=accountHolderName;
        this.balance=balance;
    }

    public void displayAccountDetails(){
        System.out.println("Account Holder: "+accountHolderName);
        System.out.println("Balance: $"+balance);
    }

    public void calculateInterest(){
        System.out.println("Interest calculation for a generic bank account");
    }

    public void applyServiceCharges(){
        System.out.println("Service charges applied for a generic bank account");
    }
}

class SavingsAccount extends BankAccount{
    private double interestRate;

    public SavingsAccount(String accountHolderName, double balance, double interestRate){
        super(accountHolderName, balance);
        this.interestRate=interestRate;
    }

    @Override
    public void calculateInterest(){
        double interest=balance*interestRate/100;
        balance+=interest;
        System.out.println("Interest calculated and added to Savings Account. New balance: $"+balance);
    }

    @Override
    public void applyServiceCharges(){
        System.out.println("No service charges for Savings Account");
    }
}

class CurrentAccount extends BankAccount{
    private double serviceCharge;

    public CurrentAccount(String accountHolderName, double balance, double serviceCharge){
        super(accountHolderName, balance);
        this.serviceCharge=serviceCharge;
    }

    @Override
    public void calculateInterest(){
        System.out.println("No interest for Current Account");
    }

    @Override
    public void applyServiceCharges(){
        balance-=serviceCharge;
        System.out.println("Service charges applied for Current Account. New balance: $"+balance);
    }
}

public class BankAccountManagement{
    public static void main(String[] args) {
        BankAccount savings=new SavingsAccount("Pradeep", 1000, 5);
        savings.displayAccountDetails();
        savings.calculateInterest();
        savings.applyServiceCharges();

        System.out.println();

        BankAccount current=new CurrentAccount("Nitin", 2000, 50);  // Upcasting
        current.displayAccountDetails();
        current.calculateInterest();
        current.applyServiceCharges();
    }
}