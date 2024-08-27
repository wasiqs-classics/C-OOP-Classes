#include <iostream>
#include <string>

using namespace std;

class Numbs {
	public:
		double a,b;
		Numbs(): a(10), b(20); // default
		Numbs(const Numbs& other){ // copy constructor
			a = other.b;
			b = other.a;
		}
		
		double Divide(double n1, double n2){
			n1 = a;
			n2 = b;
			return a/b;
		}
};

int main(){
	Numbs num1;
	cout << num1.Divide(num1.a, num1.b) << endl;
	
	Numbs num2 = num1; // copying
	cout << num2.Divide(num2.a, num2.b) << endl;
	
	
	return 0;
}
