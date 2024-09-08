#include <iostream>

using namespace std;

class Employee{
	
	private:
		int EmployeeId;
		string* EmployeeName;
		 	
	public: 
		// Creating Constructors with parameters and assigning some defaults
		
		Employee(int id=0, string name=""){
			EmployeeId = id;
			EmployeeName = new string; // creating a dynamic space for Employee Name later
			*EmployeeName = name;
		}
		
		// Now for Copy Constructor
		
		Employee(const Employee& objEmp){
			EmployeeId = objEmp.EmployeeId; 
			EmployeeName = new string;
			*EmployeeName = *(objEmp.EmployeeName);	// This line will go to the address of EmployeeName
			// of objEmp and de-ference it to copy its content and then paste the contents of that address
			// into the new object EmployeeName
		}
		
		// Now we have to destroy the memory taken by the obj. 
		
		// Destructor 
		
		~Employee(){
			delete EmployeeName; // we are only deleting Employee name because its in heap memory. Id is automatically deleted
		}
		
		// Proof of Deep Copying. 
		
		void updateEmployeeDetails(int id, string name){
			EmployeeId = id;
			*EmployeeName = name;
		}
		
		// Display details
		
		void DisplayEmployeeDetails(){
			cout << "Employee ID: " << EmployeeId << endl;
			cout << "Employee Name: " << *EmployeeName << endl;
		}
	
	
};


int main(){
	
	// Creating first Object
	Employee Employee1(1, "Kashif");
	Employee Employee2 = Employee1;
	
	// Display:
	Employee1.DisplayEmployeeDetails();
	Employee2.DisplayEmployeeDetails();
	
	// Update
	Employee1.updateEmployeeDetails(2,"Mr. Kashif");
	
	// Display again:
	Employee1.DisplayEmployeeDetails();
	Employee2.DisplayEmployeeDetails();
	
	
	
	return 0;
}
