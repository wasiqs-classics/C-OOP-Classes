#include <iostream>

using namespace std;

class Complex {
	private:
		double real;
		double imaginary;
		
	public:
		// we need three constructors
		
		// default constructor - with both values zero
		
		Complex() : real(0), imaginary(0){
		}
		
		// constructor with single parameter
		
		Complex(double realPart) : real(realPart), imaginary(0){
		}
		
		// constructor with double parameters
		
		Complex(double r, double i) : real(r), imaginary(i) {
		}
		
		// Get the values
		
		double getReal(){
			return real;
		}
	
		double getImaginary(){
			return imaginary;
		}
		
		// NOW OVERLAODING PART
		
		// overload equality operator
		bool operator == (const Complex& other) {
			return real == other.real && imaginary == other.imaginary;
		}
		
		// overload addition operator
		
		Complex operator + (const Complex& other){
			return Complex(real + other.real, imaginary + other.imaginary);
		}
		
		// overload subtraction operator
		
		Complex operator - (const Complex& other){
			return Complex(real - other.real, imaginary - other.imaginary);
		}
		
		// overloading multiplication
		
		
		Complex operator * (const Complex& other) {
			return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
		}
		
		
};

int main(){
	Complex cmpl1(3,4);
	Complex cmpl2(1,2);
	
	cout << "Complex 1: " << "<" << cmpl1.getReal() <<"+ " << cmpl1.getImaginary() << "i>" << endl;
	cout << "Complex 2: " << "<" << cmpl2.getReal() <<"+ " << cmpl2.getImaginary() << "i>" << endl;
	
	Complex c1 = cmpl1 + cmpl2;
	Complex c2 = cmpl1 - cmpl2;	
	Complex c3 = cmpl1 * cmpl2;
	
	cout << "Complex 3: " << "<" << c1.getReal() <<"+ " << c1.getImaginary() << "i>" << endl;
	cout << "Complex 4: " << "<" << c2.getReal() <<"+ " << c2.getImaginary() << "i>" << endl;
	cout << "Complex 5: " << "<" << c3.getReal() <<"+ " << c3.getImaginary() << "i>" << endl;
	
	return 0;
}
