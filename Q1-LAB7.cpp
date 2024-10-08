#include <iostream>

using namespace std;

class Animal {
	protected:
		int age;
		string name;
		string gender;
		
	public:
		// Constructor for Animals
		Animal(int a, string n, string g) : age(a), name(n), gender(g){
		}
		
		// Virtual method for Animal
		// Virtual because it can be override from the derived classes.
		virtual void animalSound() const{
			cout << "Animal is making the sound" << endl;
		}
		
		// Method to display Animal Details
		void displayDetails() const{
			cout << "Name: " << name << " , Age: " << age << " , Gender: " << gender << endl;
			animalSound();
		}
};

class Dog : public Animal {
	public:
		// Constructor for DOG
		Dog(int a, string n, string g) : Animal(a, n, g){
		}
		
		// Method for Dog
		void animalSound() const override{
			cout << "Bark Bark" << endl;
		}
	
};

class Frog : public Animal {
	public:
		// Frog Constructor
		Frog(int a, string n, string g) : Animal(a, n, g){
		}
		
		// Method for Frog
		void animalSound() const override{
			cout << "Trrrr Trrr" << endl;
		}
};

class Cat : public Animal {
	public:
		// Cat Constructor
		Cat(int a, string n, string g) : Animal(a, n, g){
		}
		
		// Method for Cat
		void animalSound() const override{
			cout << "Meow Meow" << endl;
		}
};

class Kitten : public Cat {
	public:
		// Kitten Constructor
		Kitten(int a, string n, string g) : Cat(a, n, g){
		}
		// Method for Kitten
		void animalSound() const override{
			cout << "Mama Mama" << endl;
		}	
};

class TomCat : public Cat {
	public:
		// TomCat Constructor
		TomCat(int a, string n, string g) : Cat(a, n, g){
		}
		// Method for TomCat
		void animalSound() const override{
			cout << "Tom Meow" << endl;
		}	
};



int main(){
	// let's make array pointers of our animals
	Animal* myAnimals[] = {
		new Dog(10, "Tommy", "Male"),
		new Frog(1, "Green", "Female"),
		new Cat(2, "Mano Billi", "Female"),
		new Kitten(1, "Ginger", "Male"),
		new TomCat(3, "Tom", "Male")
	};
	
	// displaying the details of each animal using range based loops
	
	for (Animal* animal : myAnimals){
		animal->displayDetails();
		cout << endl;
		cout << "===============" << endl;
	}
	
	// its good practice to free the memory as well
	
	for (Animal* animal : myAnimals){
		delete animal;
	}
	
	return 0;
}
