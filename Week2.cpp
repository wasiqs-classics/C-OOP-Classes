#include <iostream>
#include <string>

using namespace std;

class ATM {
	private:
		// Properties
		int pass;
		double balance;	
	
	public:
		
		// We now have to encapsulate
		
		// Setters are void, Getters belong to specific data type (mostly)
		
		// With constructors, we can avoid get / set because same can be done with constructors 
		
//		void setPass(int p){
//			pass = p;
//		}
//		
//		int getPass(){
//			return pass;
//		}
//		
//		void setBalance(double b){
//			balance = b;
//		}
//		
//		double getBalance(){
//			return balance;
//		}
		
		// CONSTRUCTORS
		
		// DEFAULT CONSTRUCTOR - Here we have assigned default values
		ATM(): pass(1234), balance(10){};
		
		// PARAMETERIZED CONSTRUCTOR - Here we can assign values. 
		ATM(int p, double b) : pass(p), balance(b){
		};
		
			
		// Method
		void deposit(double amount){
			balance += amount;
		}
		
		void withdraw(double amount){
			if(amount <= balance){
				balance -= amount;
			} else {
				cout << "Insufficient Balance for this transaction" << endl;
			}
		}
		
		void display(){
			cout << "ACCOUNT BALANCE: " << balance << endl;
		}
};	

int main(){
	
	ATM atmObj;
//	atmObj.setPass(1234);
//	atmObj.setBalance(1000);
	
	// checking our balance
	atmObj.display();
	
	// add some amount
	atmObj.deposit(350.5);
	
	// also withdraw
	atmObj.withdraw(200.00);
	
	// updated balance
	atmObj.display();
	
	return 0;
}
