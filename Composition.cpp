#include<iostream>
using namespace std;

// Whole Class Contains Part Class as private member 

class Part{
    public:
        Part(){
            cout << "Part class initiated" << endl;
        }
        ~Part(){
            cout << "Part class destroyed" << endl;
        }
};

class Whole{
    private:
        Part part; // composition, part obj is a part of the whole class. 

    public:
        Whole(){
            cout << "Whole class initiated" << endl;
        }

        ~Whole(){
            cout << "Whole class destroyed" << endl;
        }
};





int main(){

    Whole wholeObj;

    return 0;
}