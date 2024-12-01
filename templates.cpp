// Templates - improves code usability 

#include <iostream>

using namespace std;

// Functional Templates

template <typename T>
T findMax(T x, T y)
{
    if (x > y) {
        return x;
    } else {
        return y;
    }
}


template <typename K>
class Array
{
public:
    K array[10];

    void fillAray (K value) {
        for (int i = 0; i < 10; i++){
            array[i] = value;
        }
    }

    K valueAt (int index) {
        return array[index];
    }

};




int main(){

    // cout << findMax<int>(10,12) << endl;
    // cout << findMax<double>(5.5, 3.14) << endl;
    // cout << findMax<char>('a', 'k') << endl;

    Array<int> arr1;
    arr1.fillAray(5);

    for (int i = 0; i < 10; i++){
        cout << "array value at: " << i << " is " << arr1.valueAt(i) << endl;
    }

        Array<string> arr2;
    arr2.fillAray("ABC");

    for (int i = 0; i < 10; i++){
        cout << "array value at: " << i << " is " << arr2.valueAt(i) << endl;
    }

    return 0;
}