#ifndef PA2_H
#define PA2_H
#include <string.h>

using namespace std;

class LinkedList {

//defining the Node structure to be accessed by the LinkedList class member functions
struct Node {
    string data;
    Node *next;
};

//Member functions and variables of the LinkedList
    Node *head;
    public:
        int size();
        void add();
        LinkedList(string status);
        string status();
        void print();
        void initialize();
        
};

LinkedList::LinkedList(string status){
    head = new Node();
    head->data = status;
}

/*Determines the size of the list
int LinkedList::size(void) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        temp = temp -> next;
        count++;
    }
    return count;
}
*/


//Adds a new node at the end of the list. Only used to initialize the list.
void LinkedList::add() {
    if (head == NULL){
        head = new Node();  
        head->data = "FREE";
    }
    else {
        Node *temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new Node();
        temp->data = "Free";
    }
}

//
string LinkedList::status(){
    return head->data;
}


//Prints the list
void LinkedList::print(){
    Node *temp = head;
    int counter = 0;
    while (temp -> next !=NULL){
        if (counter == 8) {
            cout << "\n";
            counter = 0;
        }
        cout << "\t" << temp -> data;
        temp = temp -> next;
        counter++;
    }
}

#endif // "PA2_H"