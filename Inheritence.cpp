#include <iostream>

using namespace std;

class MainClass{
    public:
        void MainMethod1(){
            cout << "This is method 1 of main class" << endl;
        }
};

class SubClass : public MainClass{
    public:
        void SubMethod1(){
            cout << "This is method 1 of the sub class" << endl;
        }

        void MainMethod1(){
            cout << "Main method is hijacked!" << endl;
        }
};

int main(){
    SubClass sub1;
    sub1.MainMethod1();
    sub1.SubMethod1();
    MainClass main1;
    main1.MainMethod1();

    return 0;
}