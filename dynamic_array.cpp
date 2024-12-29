#include <iostream>
#include <stdexcept>

using namespace std;

class DynamicArray {
    private:
        int *arr;
        int currentSize;
        int capacity;

        void resize(){
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < currentSize; i++){
                newArr[i] = arr[i];
            }
        delete[] arr;
        arr = newArr;
        }
    public:
        // Constructor
        DynamicArray() : currentSize(0), capacity(2) {
            arr = new int[capacity];
        }
        // Destructor
        ~DynamicArray(){
            delete[] arr;
        }
        // Add element
        void add(int value){
            if (currentSize == capacity){
                resize();
            }
            arr[currentSize++] = value;
        }

        // Get element
        int get(int i){
            if (i < 0 || i >= currentSize){
                throw out_of_range("Index out of bounds");
            }
            return arr[i];
        }

        // Update element at index i
        void update(int index, int value){
            if (index < 0 || index >= currentSize){
                throw out_of_range("Index out of bounds");
            }
            arr[index] = value;
        }

        void remove(int i){
            if (i < 0 || i >= currentSize){
                throw out_of_range("Index out of bounds");
            }
            // In the following loop, we shift all elements to the left (this is like deleting the element at index i)
            // Suppose we have an array [1, 2, 3, 4, 5] and we want to delete the element at index 2 (which is 3)
            // first we shift all elements to the left starting from index 2
            // [1, 2, 4, 5, 5]
            for (int j = i; j < currentSize - 1; j++){
                arr[j] = arr[j + 1];
            }
            --currentSize;
        }

        int size(){
            return currentSize;
        }
};

int main(){
    DynamicArray da;
    da.add(10);
    da.add(20);
    da.add(30);
    da.add(40);
    da.add(50);

    da.update(2, 100);

    for (int i = 0; i < da.size(); i++){
        cout << da.get(i) << " ";
    }

    cout << endl;

    da.remove(1);
    for (int i = 0; i < da.size(); i++){
        cout << da.get(i) << " ";
    }

    cout << endl;
    return 0;
}