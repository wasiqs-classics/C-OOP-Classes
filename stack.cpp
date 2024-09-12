#include <iostream>
#include <stack>

using namespace std;

int main(){
	
	stack <int> stack1;
	
	cout << "The size of the stack is: " << stack1.size() << endl;
	
	if (stack1.empty()) {
		cout << "Stack is empty" << endl;
	}

	stack1.push(10); // push = add a member to the stack. by default its added at the top.
	cout << "The size of the stack is: " << stack1.size() << endl;
	
	cout << "Top member: " << stack1.top() << endl;
	
	stack1.push(9);
	cout << "new member added" << endl;

	cout << "Top member: " << stack1.top() << endl;	
	
	stack1.pop();
	
	cout << "popped 1 member" << endl;
	cout << "Top member: " << stack1.top() << endl;	
	
	// swapping 
	
	stack <int> stack2;
	
	stack2.push(8);
	stack2.push(5);
	
	cout << "The size of the stack2  is: " << stack2.size() << endl;
	cout << "The size of the stack1 is: " << stack1.size() << endl;	
	
	cout << "performaing swap" << endl;
	
	stack2.swap(stack1);
	
	cout << "The size of the stack2  is: " << stack2.size() << endl;
	cout << "The size of the stack1 is: " << stack1.size() << endl;		
	
	cout << "Top member of stack1: " << stack1.top() << endl;
	
	// 10
	
	return 0;
}
