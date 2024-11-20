#include <iostream>

using namespace std;

class my_error : public exception{
    virtual const char* what() const noexcept{
        return "Our own error has been caught!";
    }
};


int main(){

    //string word = "Pakistan";
   

    try
    {
        // int numb = 7;
        // if (numb > 5){
        //     throw exception();
        // }
        // else {
        //     throw runtime_error("Something happened");
        // }
        
        throw my_error();

    //     int *array = new int[9999999999999];
    //    //cout << word.at(70) << endl;
    }
    catch(out_of_range& e)
    {
        cout << "Exception catght: " << e.what() << endl;
    }
    catch(exception& e){
        cout << "Bad Exception Caught: " << e.what() << endl;
    }


    
    

    return 0;
}