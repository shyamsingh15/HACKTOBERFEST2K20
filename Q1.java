/*
Write a java program to implement the following class hierarchy. Show the use of
dynamic method dispatch. In addition to all operations, show the order of execution for
constructors and demostrate the use of super keyword. Verify the balance and limit while
performing deposit and withdraw method in respective classes.
Class : Account
Members: accno, name, type, balance
Methods: constructors, displayAcDetails()
Class : SavingAccount (inherits Account)
Members : minbal, withdrawlimit, interest
Methods: consturctors, displayAcDetails(), deposit(), withdraw()
Class: CurrentAccount (inherits Account)
Members : withdrawlimit, noofTxperday, interest
Methods: consturctors, displayAcDetails(), deposit(), withdraw()
*/
import java.util.Scanner;
class Account{
	static long accno=0;
	String name;
	char type;
	double balance;
	Account(String n,char t,double b){
		//constructor
		accno++;
		name = n;
		type = t;
		balance = b;
	}
	//These methods are being overridden in child class.
	public void displayAcDetails(){}
	public void deposit(double bal){}
	public void withdraw(double bal){}
}


class SavingAccount extends Account{
	double minbal=100,withdrawlimit=50000,interest=3.12;
	SavingAccount(String name,double bal){
		super(name,'S',bal);
		System.out.println("Your Saving Account Created.");
		System.out.println("Your account number is : "+accno);
		System.out.println("Your maximum withdrawl limit per day is : "+withdrawlimit);
		System.out.println("Remember your minimum balance should not go under : "+minbal);
		System.out.println("Interest rate you will get : "+interest+" percentage per month.");
	}
	public void displayAcDetails(){
		//method overridden
		System.out.println("Name : "+name+"\tAccount Number : "+accno);	
		System.out.println("Account Type : "+type+"\tAccount Balance : "+balance);
	}
	public void deposit(double bal){
		//Deposit Method
		balance = balance+bal;
	}
	public void withdraw(double bal){
		//Withdraw method
		if(balance - bal < minbal)
			System.out.println("Sorry, your transaction is crossing minimum balance limit.");
		else{
			System.out.println("Transaction Successful");
			balance = balance - bal;
		}
	}
}


class CurrentAccount extends Account{
	double minbal=0,interest=3.12;
	int noofTxperday = 3;
	CurrentAccount(String name,double bal){
		//constructor
		super(name,'C',bal);
		System.out.println("Your Current Account Created.");
		System.out.println("Your account number is : "+ accno);
		System.out.println("Nuber of transactoin limit per day is : "+ noofTxperday);
		System.out.println("Remember your minimum balance should not go under : "+ minbal);
		System.out.println("Interest rate you will get : "+interest+" percentage.");
	}
	public void displayAcDetails(){
		//method overridden
		System.out.println("Name : "+name+"\tAccount Number : "+accno);	
		System.out.println("Account Type : "+type+"\tAccount Balance : "+balance);
	}
	public void deposit(double bal){
		//Deposit Method
		balance = balance+bal;
	}
	public void withdraw(double bal){
		//Withdraw method
		if(balance - bal < minbal)
			System.out.println("Sorry, your transaction is crossing minimum balance limit.");
		else if(noofTxperday == 0)
			System.out.println("Your Daily Transaction limit reached");
		else{
			System.out.println("Transaction Successful");
			balance = balance - bal;
			noofTxperday--;
		}
	}
}


class Q1{
	//To take input
	public static String InputDetails(){
	Scanner sc = new Scanner(System.in);
		System.out.print("Enter your name : ");
		String name = sc.next();
		return name;
	}
	public static void MasterMenu(Account a){
		Scanner sc = new Scanner(System.in);
		boolean next = true;
		double bal;
		while(next){
			System.out.println("\n\nPress 1 to withdraw your money.");
			System.out.println("Press 2 to deposit money.");
			System.out.println("Press 3 to show your account information.");
			System.out.println("Press 4 to exit from this menu.");
			System.out.print("Enter your choice : ");
			int ch = sc.nextInt();
			switch(ch){
				case 1:
					System.out.println("Enter the amount you want to withdraw : ");
					bal = sc.nextDouble();
					a.withdraw(bal);
				break;
				case 2:
					System.out.println("Enter the amount you want to withdraw : ");
					bal = sc.nextDouble();
					a.deposit(bal);
				break;
				case 3:
					a.displayAcDetails();
				break;
				case 4:
					next = false;
				break;
				default:
					System.out.println("Wrong Choice ");
				break;
			}
		}
	}
	//Driver Code
	public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
		boolean next = true;
		while(next){
			System.out.print("Do you want to open an account with us?\nPress Y to yes or N to exit.\nChoice : ");
			int ch = sc.next().charAt(0);
			if(ch == 'Y' || ch == 'y'){
				System.out.print("Want to open a SavingAccount or CurrentAccount\nPress S for saving and C for current.\nChoice : ");
				int at = sc.next().charAt(0);
				if(at == 'S' || at == 's'){
					String ip = InputDetails();
					System.out.println("Minimum balance should be 100");
					System.out.print("Enter the amount to deposit : ");
					double bal = sc.nextDouble();
					SavingAccount s = new SavingAccount(ip,bal);
					//Saving reference of object of SavingAccount in Account ref varriable.
					Account a = s;
					MasterMenu(a);
				}
				else if(at == 'C' || at == 'c'){
					String ip = InputDetails();
					System.out.println("Minimum balance should be 0");
					System.out.print("Enter the amount to deposit : ");
					double bal = sc.nextDouble();
					CurrentAccount c = new CurrentAccount(ip,bal);
					//Saving reference of object of CurrentAccount in Account ref varriable.
					Account a = c;
					MasterMenu(a);
				}
				else{
					System.out.println("Wrong Choice!!!");
					continue;
				}
			}
			else if(ch == 'N' || ch == 'n'){
				next = false;
			}
			else
				System.out.println("Wrong Choice");
		}
	}
}