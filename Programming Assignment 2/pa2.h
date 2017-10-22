#ifndef PA2_H
#define PA2_H
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>

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
        void insert(int size, string name);
        
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
        temp->data = "FREE";
    }
}

// 
// string LinkedList::status(){
//     return head->data;
// }


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

void LinkedList::insert(int size, string name){
    Node *current = head;
    int nodes = ceil(size/4.0);

    int available = 0;
    int position = 0;

    //Check if there is space available
    while (current -> next != NULL) {
        if (current -> data == "FREE"){
            available++; 
            position++; 
            if (available == nodes) {
                break;
            }
        } else {
            available = 0;
            position++;
        }
        current = current -> next;
    }
    
    //If there is not enough memory available
    if (available < nodes) {
        cout << "ERROR, not enough memory for Program " << name << endl;

    } else if (available == nodes) { //There is enough memory for the program

        //Adds the program at the position found. Iterates through the position minus the available spaces minus - 1.
        Node *temp = head;    
        int i = 0;
        int filled = 0;
            while (temp -> next != NULL && filled != nodes) {
                if (temp -> data == "FREE" && ((i >= position - available) && i < position)){
                    temp -> data = name;
                    filled++;
                    cout << "Added " << filled << " nodes" << endl;
                }
            temp = temp -> next;
            i++;
        }

        cout << "Program " << name <<" successfully added" << endl;
    }
}

#endif // "PA2_H"