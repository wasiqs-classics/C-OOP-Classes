#include<iostream>

using namespace std;

// Operator overloading 

// Arithematic Operators + - * / 

// Complex Numbers (real + imaginary) (3 + 4i)

class ComplexNumber {
    private:
        double realPart;
        double imaginaryPart;
    public:
        // Constructor - Default
        ComplexNumber() : realPart(0), imaginaryPart(0) {}

        // Constructor Parametric
        ComplexNumber(double real, double imaginary) : realPart(real), imaginaryPart(imaginary){}

        // getter functions
        double getRealPart() {
            return realPart;
        }

        double getImaginaryPart() {
            return imaginaryPart;
        }

        // Arithmatic Overloading 
        ComplexNumber operator+ (const ComplexNumber& someObject){
            return ComplexNumber(realPart + someObject.realPart, imaginaryPart + someObject.imaginaryPart);
        }

        ComplexNumber operator- (const ComplexNumber& someObject){
            return ComplexNumber(realPart - someObject.realPart, imaginaryPart - someObject.imaginaryPart);
        }

        ComplexNumber operator* (const ComplexNumber& someObject){
            return ComplexNumber(realPart * someObject.realPart - imaginaryPart * someObject.imaginaryPart, realPart * someObject.imaginaryPart + imaginaryPart * someObject.realPart); // (a+bi) (c+di) => (ac - bd, ad + bc)
        }

        // For increment and decrement operators we have either prefix or postfix methods. ++something, something++

        // Unary Operators ++, --
        // Prefix Increment / decrement 
        ComplexNumber& operator++ (){
            ++realPart;
            ++imaginaryPart;
            return *this;
        }
        ComplexNumber& operator-- (){
            --realPart;
            --imaginaryPart;
            return *this;
        }

        // Postfix Increment / decrement
        ComplexNumber operator++(int){
            ComplexNumber tempObj = *this;
            ++realPart;
            ++imaginaryPart;
            return tempObj;
        }
        ComplexNumber operator--(int){
            ComplexNumber tempObj = *this;
            --realPart;
            --imaginaryPart;
            return tempObj;
        }

        // Comparison Operators ==, !=, <, etc. 

        // Equality Operators

        bool operator==(const ComplexNumber& otherObj){
            return realPart == otherObj.realPart && imaginaryPart == otherObj.imaginaryPart;
        }

        // Inequality
        bool operator!=(const ComplexNumber& otherObj){
            return realPart != otherObj.realPart || imaginaryPart != otherObj.imaginaryPart;
        }

        // Overloading of Insertion and Extraction Operators

        // Insertion Opertor - used with friend function and output stream (ostream)

        friend ostream& operator<<(ostream& out, const ComplexNumber& other){
            out << "<" << other.realPart << " + " << other.imaginaryPart << "i>";
            return out;
        }

        // Extraction Operator

        friend istream& operator>>(istream& in, ComplexNumber& other){
            cout << "Real part: ";
            in >> other.realPart;
            cout << "Imaginary part: ";
            in >> other.imaginaryPart;
            return in;
        }

};



int main(){

    ComplexNumber C1(3,4);
    ComplexNumber C2(5,6);

    cout << C1 << endl;

    ComplexNumber C3 = C1 + C2; // + Operator 
    ++C3;
    cout << "Prefix Increment" << endl;
    cout << "Complex number 3: " << "<" << C3.getRealPart() << " + " << C3.getImaginaryPart() << "i>" << endl;
    --C3;
    cout << "Prefix decrement" << endl;
    cout << "Complex number 3: " << "<" << C3.getRealPart() << " + " << C3.getImaginaryPart() << "i>" << endl;
    C3++;
    cout << "Postfix Increment" << endl;
    cout << "Complex number 3: " << "<" << C3.getRealPart() << " + " << C3.getImaginaryPart() << "i>" << endl;
    C3--;
    cout << "Postfix decrement" << endl;
    cout << "Complex number 3: " << "<" << C3.getRealPart() << " + " << C3.getImaginaryPart() << "i>" << endl;
    cout << "Checking Comparison Operators" << endl;
    if (C1 == C2){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // using >> operator

    ComplexNumber C4;
    cout << "Enter the complex number: " << endl;
    cin >> C4;
    cout << "Your Complex Number is " << C4 << endl;

    return 0;
}