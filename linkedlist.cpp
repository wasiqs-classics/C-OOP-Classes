// linked list - nodes
// singly linked list - head node -> node 1 -> node 2 -> ... -> node n -> nullptr
// doubly linked list - head node -> node 1 <-> node 2 <-> ... <-> node n -> nullptr
// circular linked list - head node -> node 1 -> node 2 -> ... -> node n -> head node
// circular doubly linked list - head node -> node 1 <-> node 2 <-> ... <-> node n -> head node

#include <iostream>

using namespace std;

// Node 

struct Node {
    int data;
    Node* next;
};

// linked list class

class LinkedList {
    private:
        Node* head;
    public:
        // Constructor
        LinkedList() : head(NULL){}

        // Methods
        // insert node at the beginning

        void insertAtTheBeginning(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        // insert node at the end

        void insertAtTheEnd(int value){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;

        // check for empty list
        if (!head){
            head = newNode;
            return;
        }
        // traverse to the end of the list
        Node* temp = head;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        }

        // insert node at a given position

        void insertAtAPosition(int value, int position){
            if (position < 1){
                cout << "Invalid position" << endl;
                return;
            }
            if (position == 1){
                insertAtTheBeginning(value);
                return;
            }
            Node* newNode = new Node();
            newNode->data = value;
            // traverse to the position
            Node* temp = head;
            for (int i = 1; i < position - 1; i++){
                temp = temp->next;
            }
            // check for out of range position
            if (!temp){
                cout << "Invalid position: Out of range" << endl;
                delete newNode;
                return;
            }
            // now since we are at the right position so we insert the node
            newNode->next = temp->next;
            temp->next = newNode;
        }

        // Lets delete from the beginning
        void deleteFromBeginning(){
            if (!head){
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // delete from the end
        void deleteFromEnd(){
           if (!head){
                cout << "List is empty" << endl;
                return;
            }
            // delete the only node
            if (!head->next){
                delete head;
                head = NULL;
                return;
            }
            // traverse to the end of the list
            Node* temp = head;
            while (temp->next->next){ // second last node. 
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }

        // delete from a given position
        void deleteFromAPosition(int position){
            if (position < 1){
                cout << "Invalid position" << endl;
                return;
            }
            if (position == 1){
                deleteFromBeginning();
                return;
            }
            Node* temp = head;
            for (int i = 1; i < position - 1; i++){
                temp = temp->next;
            }
            // out of range
            if (!temp || !temp->next){
                cout << "Invalid position: Out of range" << endl;
                return;
            }
            Node* nodeToBeDeleted = temp->next;
            // updating the next pointer of the previous node
            temp->next = temp->next->next;
            // now since we have the proper binding so we can delete the node
            delete nodeToBeDeleted;
        }

        void display(){
            if (!head){
                cout << "List is empty" << endl;
                return;
            }

            Node* temp = head;
            while (temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    LinkedList list;
    list.insertAtTheBeginning(1); // insert 1 at the beginning
    list.insertAtTheBeginning(2); // insert 2 at the beginning
    list.insertAtTheBeginning(3); // insert 3 at the beginning
    list.insertAtTheEnd(4); // insert 4 at the end
    list.insertAtTheEnd(5); // insert 5 at the end
    list.insertAtAPosition(6, 3); // insert 6 at position 3
    list.display();  // display the list output: 3 2 6 1 4 5
    list.deleteFromBeginning(); // delete from the beginning
    list.display(); // display the list output: 2 6 1 4 5
    list.deleteFromEnd(); // delete from the end
    list.display(); // display the list output: 2 6 1 4
    list.deleteFromAPosition(2); // delete from position 2
    list.display(); // display the list output: 2 1 4
    return 0;
}
