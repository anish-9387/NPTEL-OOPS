class BankAccount{
    private String accountHolderName, accountNumber;
    private double balance;

    public BankAccount(String accountHolderName, String accountNumber, double initialBalance){
        this.accountHolderName=accountHolderName;
        this.accountNumber=accountNumber;
        setBalance(initialBalance);
    }

    public String getAccountHolderName(){
        return accountHolderName;
    }

    public void setAccountHolderName(String accountHolderName){
        this.accountHolderName=accountHolderName;
    }

    public String getAccountNumber(){
        return accountNumber;
    }

    public void setAccountNumber(String accountNumber){
        this.accountNumber=accountNumber;
    }

    public double getBalance(){
        return balance;
    }

    public void setBalance(double balance){
        if(balance>=0){
            this.balance=balance;
        }
        else{
            System.out.println("Invalid balance. Balance cannot be negative");
        }
    }

    public void deposit(double amount){
        if(amount>0){
            balance+=amount;
            System.out.println("Successfully deposited: "+amount);
        }
        else{
            System.out.println("Invalid amount");
        }
    }

    public void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance-=amount;
            System.out.println("Successfully withdrawn: "+amount);
        }
        else if(amount>balance){
            System.out.println("Insufficient balance");
        }
        else{
            System.out.println("Invalid withdrawl amount");
        }
    }

    public void displayAccountDetails(){
        System.out.println("Account holder name: "+accountHolderName);
        System.out.println("Account number: "+accountNumber);
        System.out.println("Balance: "+balance);
    }
}

public class BankAccountManagementSystem{
    public static void main(String[] args) {
        BankAccount account1=new BankAccount("Hitesh", "ABC05052006", 500.00);

        account1.displayAccountDetails();
        System.out.println();

        account1.deposit(150);

        account1.withdraw(100);

        account1.withdraw(600.00);

        System.out.println();
        account1.displayAccountDetails();
    }
}
