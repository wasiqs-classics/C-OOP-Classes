#include<iostream>
#include<vector>

using namespace std;

class Stack {
	private: 
		vector<int> elements;
	
	public:
		void push(int value) {
			elements.push_back(value);
		}
		
		void pop(){
			if (!elements.empty()){
				elements.pop_back();
			} else {
				cout << "Stack is already empty" << endl;
			}	
		}
		
		int top() {
			if (!elements.empty()){
				return elements.back();
			} else {
				cout << "Stack is already empty" << endl;
			}
		}
		
		bool isEmpty() {
			return elements.empty();
		}
		
		int size(){
			return elements.size();
		}
};




int main(){
	
	Stack stack1;
	stack1.push(10);
	stack1.push(20);
	stack1.pop();
	stack1.push(30);
	cout << "Top Element is now: " << stack1.top() << endl;
	cout << stack1.isEmpty() << endl;
	cout << "Size is: " << stack1.size() << endl;
	
	return 0;
}
