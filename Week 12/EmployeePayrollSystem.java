import java.util.ArrayList;
import java.io.*;

abstract class Employee implements Serializable{
    private String name;
    private String id;

    public Employee(String name, String id){
        this.name=name;
        this.id=id;
    }

    public String getName(){
        return name;
    }

    public String getId(){
        return id;
    }

    public abstract double calculateSalary();
}

class PermanentEmployee extends Employee{
    private double baseSalary;

    public PermanentEmployee(String name, String id, double baseSalary){
        super(name,id);
        this.baseSalary=baseSalary;
    }

    @Override
    public double calculateSalary(){
        return baseSalary + (0.2*baseSalary);  // Base + 20% benefits
    }

    public double getBaseSalary(){
        return baseSalary;
    }
}

class ContractEmployee extends Employee{
    private double hourlyRate;
    private int hoursWorked;

    public ContractEmployee(String name, String id, double hourlyRate, int hoursWorked){
        super(name,id);
        this.hourlyRate=hourlyRate;
        this.hoursWorked=hoursWorked;
    }

    @Override
    public double calculateSalary(){
        return hourlyRate*hoursWorked;
    }

    public double getHourlyRate(){
        return hourlyRate;
    }

    public int getHoursWorked(){
        return hoursWorked;
    }
}

class Intern extends Employee{
    private double stipend;

    public Intern(String name, String id, double stipend){
        super(name,id);
        this.stipend=stipend;
    }

    @Override
    public double calculateSalary(){
        return stipend;   // Fixed stipend
    }

    public double getStipend(){
        return stipend;
    }
}

class Payroll{
    private ArrayList<Employee> employees;

    public Payroll(){
        employees=new ArrayList<>();
    }

    public void addEmployee(Employee employee){
        employees.add(employee);
    }

    public void generatePayroll(){
        for(Employee emp : employees){
            System.out.println(emp.getName()+" ("+emp.getId()+"): $"+emp.calculateSalary());
        }
    }

    public ArrayList<Employee> getEmployees(){
        return employees;
    }
}

class DataHandler{
    public static void saveEmployees(ArrayList<Employee> employees, String filename){
        try(BufferedWriter writer=new BufferedWriter(new FileWriter(filename))){
            for(Employee emp : employees){
                String line="";
                if(emp instanceof PermanentEmployee){
                    line="Permanent,"+emp.getName()+","+emp.getId()+","+((PermanentEmployee)emp).getBaseSalary();
                }
                else if(emp instanceof ContractEmployee){
                    line="Contract,"+emp.getName()+","+emp.getId()+","+((ContractEmployee)emp).getHourlyRate()+","+((ContractEmployee)emp).getHoursWorked();
                }
                else if(emp instanceof Intern){
                    line="Intern,"+emp.getName()+","+emp.getId()+","+((Intern)emp).getStipend();
                }
                writer.write(line);
                writer.newLine();
            }
        }
        catch(IOException e){
            System.out.println("Error saving employees: "+e.getMessage());
        }
    }

    public static ArrayList<Employee> loadEmployees(String filename){
        ArrayList<Employee> employees=new ArrayList<>();
        try(BufferedReader reader=new BufferedReader(new FileReader(filename))){
            String line;
            while((line=reader.readLine())!=null){
                String[] parts=line.split(",");
                String type=parts[0];
                String name=parts[1];
                String id=parts[2];
                if(type.equals("Permanent")){
                    double baseSalary=Double.parseDouble(parts[3]);
                    employees.add(new PermanentEmployee(name,id,baseSalary));
                }
                else if(type.equals("Contract")){
                    double hourlyRate=Double.parseDouble(parts[3]);
                    int hoursWorked=Integer.parseInt(parts[4]);
                    employees.add(new ContractEmployee(name,id,hourlyRate,hoursWorked));
                }
                else if(type.equals("Intern")){
                    double stipend=Double.parseDouble(parts[3]);
                    employees.add(new Intern(name,id,stipend));
                }
            }
        }
        catch(IOException e){
            System.out.println("Error loading employees: "+e.getMessage());
        }
        return employees;
    }
}

public class EmployeePayrollSystem{
    public static void main(String[] args) {
        Payroll payroll=new Payroll();

        // Add employees
        payroll.addEmployee(new PermanentEmployee("Alice","P101",5000));
        payroll.addEmployee(new ContractEmployee("Bob","C202",20,100));
        payroll.addEmployee(new Intern("Charlie","I303",1500));

        // Generate payroll
        System.out.println("Payroll Summary:");
        payroll.generatePayroll();

        // Save the data
        System.out.println("\nSaving employee data...");
        ArrayList<Employee> employees=new ArrayList<>(payroll.getEmployees());
        DataHandler.saveEmployees(employees,"employees.txt");

        // Load the data
        System.out.println("\nLoading employee data...");
        ArrayList<Employee> loadedEmployees=DataHandler.loadEmployees("employees.txt");
        System.out.println("Loaded Employees");
        for(Employee emp : loadedEmployees){
            System.out.println(emp.getName()+" ("+emp.getId()+"): $"+emp.calculateSalary());
        }
    }
}