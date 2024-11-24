#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Map_Key
{
private:
    T1 key;
    T2 val;
public:
    // Constructor
    Map_Key(T1 k, T2 v) : key(k), val(v) {};

    // CHECK FUNCTION
    bool check(T1 k) const {
        return k == key;
    }

    //GET FUNCTION
    T2 get() const{
        return val;
    }

    // Overloading + operator
    Map_Key operator+(const Map_Key& other) {
        return Map_Key(key + " and " + other.key, val + other.val);
    }
};

int main(){

    Map_Key<string, int> mk_1("One", 1), mk_2("Two", 2);
    Map_Key<string, int> mk_3 = mk_1 + mk_2;

    vector <Map_Key<string, int>> v = {mk_1, mk_2, mk_3};

    string input;
    cout << "Enter some Key: ";
    cin >> input;

    bool val_found = false;

    for (const auto& var : v){
        if (var.check(input)) {
            cout << "Value: " << var.get() << endl;
            val_found = true;
            break;
        }
    }

    if (!val_found) {
        cout << "Key never found!" << endl;
    }

    return 0;
}

