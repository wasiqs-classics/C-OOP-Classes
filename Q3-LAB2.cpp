#include <iostream>

using namespace std;

// Defining the Global Variable

int countOfBooks = 0;

class Book{
	private:
		long bookNumber;
		string bookTitle;
		double salesPrice;
		
		
	public:
		// Constructor (with default values for arguments)
		Book(long bookNum = 0, const string& title="", double bookPrice=0.0){
			bookNumber = bookNum;
			bookTitle = title;
			salesPrice = bookPrice < 0 ? 0.0 : bookPrice; // ternary operator (short hand if - else)
			countOfBooks++;
			cout << "The object of class Book: " << bookTitle << " is created. " << endl;
			cout << "This is the " << countOfBooks << " book." << endl;
		}
		
		// Now Destructor
		~Book(){
			// decrement the global counter
			countOfBooks--;
			cout << "The object of class Book: " << bookTitle << " is destryed. " << endl;
			cout << "There are still " << countOfBooks << " books." << endl;	
		}
		
		// Displaying the books details with Display method. 
		
		void Display(){
			cout << "Book Number: " << bookNumber << endl;
			cout << "Book Title: " << bookTitle << endl;
			cout << "Book Price: Rs. " << salesPrice << endl;
		}
		
		// Set Method for Book Price
		
		void setBookPrice(double price){
			salesPrice = price;
		}
		
		double getBookPrice(){
			return salesPrice;
		}
};



int main(){
	
	Book book1(10000001, "Atomic Habits", 250.5);
	Book book2(10000002, "7 Habits", 170.35);
	Book book3(10000003, "Rich Dad Poor Dad", -5.6);
	Book book4(10000004, "Programming with C++", 12);
	
	book1.Display();
	book2.Display();
	book3.Display();
	book4.Display();
	
	
	
	return 0;
}
