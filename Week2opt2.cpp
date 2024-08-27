#include <iostream>
#include <string>

using namespace std;

class ATM {
	private:
		// Properties
		int pass;
		double balance;	
	
	public:
		
		// CONSTRUCTORS
		
		// DEFAULT CONSTRUCTOR - Here we have assigned default values
		ATM(): pass(1234), balance(0){};
		
		// PARAMETERIZED CONSTRUCTOR - Here we can assign values. 
		ATM(int p, double b) : pass(p), balance(b){
		};
		
		// COPY CONSTRUCTOR
		ATM(const ATM& other){
			balance = other.balance;
			pass = other.pass;
		}
		
		// Destructor - runs automatically.
		~ATM(){
			cout << "Destroying the object" << endl;
		}
	
		// Method
		void deposit(double amount){
			balance += amount;
		}
		
		// Let's overload deposit function
		void deposit(double percentage, bool isThisPercentage){
			if(isThisPercentage){
				balance += balance*(percentage/100);
			}
		}
		
		// Operator Overloading on + sign
		ATM operator + (const ATM& obj){ // obj here represents an object of our class. 
			ATM result;
			result.balance = this->balance + obj.balance;
			return result;
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
	atmObj.deposit(350.5); // direct deposit
	
	// also withdraw
	atmObj.withdraw(200.00);
	
	// updated balance
	atmObj.display();
	
	// percentage desposit
	atmObj.deposit(50, true);
	
	// updated balance
	atmObj.display();
	
	ATM obj1(123, 1000), obj2(321, 500);
	ATM obj3 = obj1 + obj2;
	obj3.display();
	
	

	return 0;
}
