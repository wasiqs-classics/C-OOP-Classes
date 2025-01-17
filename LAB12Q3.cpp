#include <iostream>

using namespace std;

template <typename T>
class Circle
{
private:
    T rad;
public:
    // Constructor of the class
    Circle(T r = 0) : rad(r) {};

    // Overloading + operator so that we can add some value to the radius
    void operator + (T value) {
        rad += value;
    }

    // Overloading + operator again for the addition of two radii 
    Circle operator+ (const Circle& other) {
        return Circle(rad + other.rad);
    }

    // Overloading << operator to display the result
    friend ostream& operator<< (ostream& os, const Circle& c){
        os << c.rad;
        return os;
    }

};


int main(){
    Circle<int> c1(5), c2;
    c2 + 3;
    Circle<int> c3 = c1 + c2;
    Circle<double> c4(1.5);
    c4 + 1.2;

    cout << c3 << " " << c4 << endl;

    return 0;
}