#include <iostream>
using namespace std;

class NumDays {
	private:
		int hours;	
		
	public:
		// Constructor to accept the number of hours as parameters
		NumDays(int h = 0) : hours(h){
		}
		
		// storing and retrieiving hours
		
		// first we store - "set"
		
		void setHours(int h){
			hours = h;
		}
		
		// second we retrieve "get"
		
		int getHours() {
			return hours;
		}
		
		// get days from hours. 
		
		double getDays() {
			return hours/8.0; // since 1 DAY is Equal to 8 hours
		}
		
		// overloading + operator
		NumDays operator + (const NumDays& other){
			return NumDays(hours + other.hours);
		}
		
		// overloading - operator
		NumDays operator - (const NumDays& other){
			return NumDays(hours - other.hours);
		}
		
		// overloading the (prefix) increament operator ++x
		
		NumDays& operator ++ (){
			++hours;
			return *this;
		}
		
		// overloading the (postfix) increament operator x++
		
		NumDays operator ++ (int){
			NumDays temp = *this;
			++hours;
			return temp;
		}

		// overloading the (prefix) decrement operator --x
		
		NumDays& operator -- (){
			--hours;
			return *this;
		}
		
		// overloading the (postfix) decrement operator x--
		
		NumDays operator -- (int){
			NumDays temp = *this;
			--hours;
			return temp;
		}		
		
	
	
};


int main(){
	
	// testing our classes
	
	NumDays obj1(12);
	NumDays obj2(8);
	
	cout << "For Object 1: " << endl;
	cout << "Hours: " << obj1.getHours() << endl;
	cout << "Days: " << obj1.getDays() << endl;
	cout << "For Object 2: " << endl;
	cout << "Hours: " << obj2.getHours() << endl;
	cout << "Days: " << obj2.getDays() << endl;
	NumDays obj3 = obj1 + obj2; // + operator
	NumDays obj4 = obj1 - obj2; // - operator
	cout << "For Object 3: " << endl;
	cout << "Hours: " << obj3.getHours() << endl;
	cout << "Days: " << obj3.getDays() << endl;
	cout << "For Object 4: " << endl;
	cout << "Hours: " << obj4.getHours() << endl;
	cout << "Days: " << obj4.getDays() << endl;
	// increment
	++obj1;
	cout << "For Object 1: " << endl;
	cout << "Hours: " << obj1.getHours() << endl;
	cout << "Days: " << obj1.getDays() << endl;
	obj1++;
	cout << "For Object 1: " << endl;
	cout << "Hours: " << obj1.getHours() << endl;
	cout << "Days: " << obj1.getDays() << endl;
	// decreament
	--obj1;
	cout << "For Object 1: " << endl;
	cout << "Hours: " << obj1.getHours() << endl;
	cout << "Days: " << obj1.getDays() << endl;
	obj1--;
	cout << "For Object 1: " << endl;
	cout << "Hours: " << obj1.getHours() << endl;
	cout << "Days: " << obj1.getDays() << endl;
	
	
	return 0;
}
