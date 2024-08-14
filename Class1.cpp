#include <iostream>
using namespace std;

// Class 0.5 of OOP 

// ClASS - Blueprint for creation of Object. It contains all the information which is required to create Objects. 
// Example: Recipe of Making a Cake - Its a class
// OBJECTS - These are the actual things created from the classes
// Example: The actual baked cakes are objects of class Recipe. 

// Syntax of a Class
// class (keyword) className {
// public: (access specier)
// Class Members	
// }

// CLASS MEMBERS
// 1. Attributes (properties) - ingredients are Attibutes (data within a class) 
// 2. Methods (behaviors) - baking is a method, mixing is a method - Methods are basically functions that are created in the class. 
	
// Definition of the Class
class Recipe {
	public:
		// Attributes
		string flavor;
		int layer;
		
		// Method
		void BakeIt(){
			cout << "Baking the " << flavor << " of " << layer << " layers. " << endl; 
		}
};

class Car {
	public: 
		// Attributes
		string brand;
		string color;
		int model;
		
		// Methods
		void ignite(){
			cout << "Car is starting ...." << endl;
		}
	
};

class BankAccount {
	private:
		// Attribute
		int balance = 0;
		
	public:
		// Methods
		void deposit(int amount){
			if (amount > 0){
				balance += amount;
			}
		}
		
		int getBalance(){
			return balance;
		}
};



int main(){
	Recipe myCake; // We are creating an Object myCake belonging to class Recipe
	myCake.flavor = "Chocolate Cake";
	myCake.layer = 3;
	
	myCake.BakeIt();
	
	Car myCar;
	myCar.brand = "Honda";
	myCar.color = "White";
	myCar.model = 2024;
	
	myCar.ignite();
	
	
	BankAccount account1;
	cout << "The initial balance is: " << account1.getBalance() << endl;
	cout << "Adding balance of 1000" <<endl;
	account1.deposit(1000);
	int new_balance = account1.getBalance();
	cout << "New balance is now: " << new_balance << endl;
	
	
	
	return 0;
}
