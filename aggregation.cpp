#include <iostream>
#include <vector>

using namespace std;


class Employee {
	public:
		string empName;
		Employee(string name) : empName(name){
			cout << "Employee: " << empName << " is created." << endl;
		}
};

class Organization {
	public:
		string orgName;
		vector<Employee*> employees; // this is the aggregation part. Organization aggregates Employee
		
		// Constructor
		Organization(string name) : orgName(name){
			cout << "Organization: " << orgName << " is created." << endl;
		}
		void addEmployee(Employee* person){
			employees.push_back(person);
			cout << "Employee: " << person->empName << " has been added to the organization " << orgName << endl;
		}
		
		// Destroy 
		~Organization(){
			cout << "Organization: " << orgName << " is destroyed" << endl;
		}
};

int main(){
	Employee emp1("Wasiq");
	Employee emp2("Khan");
	
	Organization org1("ABC Corp.");
	
	// add members
	org1.addEmployee(&emp1);
	org1.addEmployee(&emp2);
	
	Organization org2("XYZ Copr");
	org2.addEmployee(&emp1);

	
	
	return 0;
}
