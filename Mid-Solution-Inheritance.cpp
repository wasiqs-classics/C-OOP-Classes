#include <iostream>
#include <string>

using namespace std;


class Publication {
	protected:
		string title;
		float price;
	
	public: 
		virtual bool isOverSize() const {
		return false;
		}	
		
		virtual void getData() {
			cout << "Enter title: " ;
			getline(cin, title);
			cout << "Enter price: " ;
			cin >> price;
		}
		
		virtual void putData() const {
			cout << "Title: " << title << endl;
			cout << "Price: " << price << endl;
		}
	
};

class Book : public Publication {
	private:
		int pageCount;
		
	public:
		// function to check if book is oversized (more than 800 pages)
		bool isOverSize() const override {
			return pageCount > 800;
		}
		
		void getData() override {
			Publication::getData();
			cout << "Enter number of pages: " ;
			cin >> pageCount;
		}
		
		void putData() const override {
			Publication::putData();
			cout << "Page Count: " << pageCount << endl;
			cout << (isOverSize() ? "The book is oversized" : "The book is not oversized") << endl;
		}
		
};

class Tape : public Publication {
	private:
		float playingTime;
		
	public:
		// function to check if book is oversized (more than 800 pages)
		bool isOverSize() const override {
			return playingTime > 90;
		}
		
		void getData() override {
			Publication::getData();
			cout << "Enter playing time (mins): " ;
			cin >> playingTime;
		}
		
		void putData() const override {
			Publication::putData();
			cout << "Playing Time: " << playingTime << endl;
			cout << (isOverSize() ? "The tape is oversized" : "The tape is not oversized") << endl;
		}
		
};


int main(){
	
	Publication* publications[10];
	int count = 0;
	char choice;
	
	do {
		cout << "Enter publication choice: (b for book, t for tape)";
		cin >> choice;
		cin.ignore();
		
		if (choice == 'b'){
			publications[count] = new Book();
		} else if (choice == 't') {
			publications[count] = new Tape();
		} else {
			cout << "Invald choice!" << endl;
			continue;
		}
		
		publications[count]->getData();
		count++;
		
		cout << "Want to add another record? (y/n)";
		cin >> choice;
		cin.ignore();
	} while (choice == 'y' && count < 10);
	
	cout << "\nPublications Details\n";
	for (int i = 0; i < count; i++){
		publications[i]->putData();
		delete publications[i];
		cout << endl;
	}
	
	return 0;
}
