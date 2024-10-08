#include <iostream>

using namespace std;

class Person{
    private:
    string fname;

    protected:
    string lname;

    public:
    Person(string fname, string lname): fname(fname), lname(lname){
        cout<<"Person's ctor called!"<<endl;
    }

    // Person(){
    //     cout<<"Person's ctor called!"<<endl;
    // }

    ~Person(){
        cout<<"Person's dtor called"<<endl;
    }

    void Set_fname(string fname){
        this->fname = fname;
    }

    void DisplayPerson(){
        cout<<fname<<endl;
        cout<<lname<<endl;
    }
};

class Student: public Person{
    private:
    string studentId;

    public:
    Student(string fname, string lname, string id): Person(fname,lname), studentId(id){
        cout<<"Student's ctor called!"<<endl;
    }

    void DisplayStudent(){
        cout<<studentId<<endl;
    }

    ~Student(){
        cout<<"Student's dtor called!"<<endl;
    }

};

class Faculty: public Person{
    private:
    string facultyId;

    public:
    Faculty(string fname, string lname, string id): Person(fname,lname), facultyId(id){
        cout<<"Faculty's ctor called!"<<endl;
    }

    void DisplayFaculty(){
        cout<<facultyId<<endl;
    }

    ~Faculty(){
        cout<<"Faculty's dtor called!"<<endl;
    }

};


int main(){
    Faculty fac("Wasiq", "Khan", "001");
    fac.DisplayPerson();
	fac.DisplayFaculty();
	Student stu("Wasiq", "Khan", "001");
	stu.DisplayPerson();
	stu.DisplayStudent();
    return 0;
}
