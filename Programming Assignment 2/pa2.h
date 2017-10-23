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
public:
    Node* getNext(){
        return this->next;
    }
    string getData(){
        return this->data;
    }
};

//Member functions and variables of the LinkedList
    Node *head;    
    public:
        int globalPosition; //position used to determine where to place a node using the worst fit algorithm
        int size();
        void add();
        LinkedList(string status);
        string status();
        void print();
        void initialize();
        void insert(int size, string name, string fit);
        void remove(string name);  
        int enoughSpace(int size);
        bool enoughSpace(int size, int position);
        int exists(string name);  
        int fragmentationStatus();
        
};

LinkedList::LinkedList(string status){
    head = new Node();
    head->data = status;
    globalPosition = 0;
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
        temp-> data = "FREE";
    }
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

void LinkedList::insert(int size, string name, string fit){
    Node *current = head;
    int nodes = ceil(size/4.0);

    //Check if there is enough memory for the program
    int position = enoughSpace(size);

    //Check if there is an existing program
    int exists = LinkedList::exists(name);
    
    //If there is not enough memory available
    if (position == 400) {
        cout << "\nERROR, not enough memory for Program " << name << "." << endl;
    } else if (exists == 1) {
        cout << "\nERROR, Program " << name << " already running." << endl;
    } else if (fit == "best") { //There is enough memory for the program
        //Adds the program at the position found. Starts adding the program at the (position - nodes)th iteration up to
        //the positionth iteration
        int i = 0; //i is used as the iterator here
        int filled = 0;
            while (current -> next != NULL && filled != nodes) {
                if (current -> data == "FREE" && ((i >= position - nodes) && i < position)){
                    current -> data = name;
                    filled++;
                }
            current = current -> next;
            i++;
        }
        cout << "\nProgram " << name << " added successfully: " << nodes << " page(s) used" << endl;
    }

    //Steps for worst fit algorithm
    if (!enoughSpace(size, globalPosition)) {
        cout << "ERROR, not enough memory for Program " << name << "." << endl;
    } else if (fit == "worst") {
        int i = 0; //i is used as the iterator here
        int filled = 0;
            while (current -> next != NULL && filled != nodes) {
                if (current -> data == "FREE" && i >= (globalPosition)){
                    current -> data = name;
                    filled++;                  
                }
            current = current -> next;
            i++;
        }
        globalPosition = i; // Adds the index of the last program added to keep track of the position in memory  
        cout << "\nProgram " << name << " added successfully: " << nodes << " page(s) used" << endl;        
    }
}

void LinkedList::remove(string name){
    int removed = 0;
    int exists = LinkedList::exists(name);
    if (exists == 1){
        Node *temp = head;
        while (temp -> next != NULL) {
            if (temp -> data == name){
                temp -> data = "FREE";
                removed++;
            }
            temp = temp -> next; 
        }
        cout << "\nProgram " << name << " successfully killed: " << removed << " page(s) reclaimed." << endl;                   
    } else {
        cout << "\nERROR, program " << name << " is not running." << endl;
    }
}

// LinkedList::Node* LinkedList::getHead(){
//     return this->head;
// }


int LinkedList::exists(string name) {
    
    int exists = 0;
    Node *temp = head;
    while (temp -> next != NULL) {
        if (temp -> data == name){
            exists = 1; // 1 represents TRUE
            break;
        }
        temp = temp -> next; 
    }
    return exists;
}

int LinkedList::enoughSpace(int size){
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
    if (available == nodes) {
        return position; //returns a position if there is a space available
    } else {
        return 400; //400 represents the error of no space available
    }
}

bool LinkedList::enoughSpace(int size, int position){
    Node *current = head;
    int nodes = ceil(size/4.0);

    bool enoughSpace = false;

    int available = 0;
    int i = 0;

    //Check if there is space available
    while (current -> next != NULL) {
        if (current -> data == "FREE" && ((i >= position && i <= (position + size)))){
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
    if (available == nodes) {
        enoughSpace = true; // returns true if there is enough space after the specified position
    }
    return enoughSpace;
}

int LinkedList::fragmentationStatus(){
    Node *current = head;
    Node *previous = NULL;
    int counter = 0;
    int index = 0;
    while (current -> next != NULL){
        if (current -> data == "FREE" && current -> next -> data != "FREE"){
            counter ++;
        }
        current = current -> next;
        index++;   
    }     
 //Resets to the head, given that this function is called more than once
    return counter;    
}

#endif // "PA2_H"