#include<iostream>
#include<vector>

using namespace std;

class Course{
	public:
		string courseName;
		Course(string name) : courseName(name){}
};

class Student{
	public:
		string studentName;
		Student(string name) : studentName(name){
		}
		
		void enroll(Course& course) { // this is where we associate the two classes
			cout << studentName << " enrolled in " << course.courseName << " course." << endl;
		}
};

int main() {
	Course course1("C++");
	Student student1("Hiba");
	student1.enroll(course1);
	
	return 0;
}
