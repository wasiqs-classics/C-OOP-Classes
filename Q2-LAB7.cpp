#include <iostream>
#include <string>

using namespace std;

class Book{
	protected:
		string title;
		string author;
		double price;
	
	public:
		// Constructor to initiaze the Book and set price to 500
		Book(string name, string writer) : title(name), author(writer), price(500){
		}
		
		// display method to display the details of the books
		virtual void Display() const {
			cout << "Book Details" << endl;
			cout << "============" << endl;
			cout << "Title: " << title << " , Author: " << author << ", Price: Rs. " << price << "/=" << endl;
		}
};

class PopularBook : public Book{
	public:
		// Constructor to set the Popular Book price to 50,000
		PopularBook(string name, string writer) : Book(name, writer){
			price = 50000;
		}
		
		// display method to display the details of the popular books
		void Display() const override {
			cout << "Book Details" << endl;
			cout << "============" << endl;
			cout << "Title: " << title << " , Author: " << author << ", Price: Rs. " << price << "/=" << endl;
		}
		
};

int main(){
	const int NumOfBooks = 5;
	Book* book[NumOfBooks]; // an array pointer to book objects of size 5
	
	// Input book details
	
	for (int i = 0; i < NumOfBooks; i++){
		string bookTitle, bookAuthor;
		cout << "Enter the title for the book # " << i + 1 << " : " ;
		getline(cin, bookTitle);
		cout << "Enter Author Name for book # " <<  i + 1 << " : " ;
		getline(cin, bookAuthor);
		
		// Now we will check the names of the authors to decide the class
		
		if (bookAuthor == "Khaled Hosseini" || bookAuthor == "Oscar Wilde" || bookAuthor == "Rembrandt"){
			book[i] = new PopularBook(bookTitle, bookAuthor);
		} else {
			book[i] = new Book(bookTitle, bookAuthor);
		}	
	}
	
	// Also printing the details of all books
	
	cout << "\nDISPLAYNG BOOKS: " << endl;
	cout << "================ " << endl;
	
	for (int i = 0; i < NumOfBooks; i++){
		book[i]->Display();
	}
	
	// Good practice! Free memory!
	
	for (int i = 0; i < NumOfBooks; i++){
		delete book[i];
	}
	
	
	
	
	return 0;
}
