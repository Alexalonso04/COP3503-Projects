#ifndef PA2_H
#define PA2_H

using namespace std;

//defining the Node structure
struct Node {
    string data;
    Node *next;

public:
    string getData(){
        return this->data;
    }
};

class LinkedList {
    Node *head;
    public:
        int size();
        void add();
        LinkedList(string space);
        string isFree();
        
};

LinkedList::LinkedList(string space){
    head = new Node();
    head->data = space;
}

int LinkedList::size(void) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        temp = temp -> next;
        count++;
    }
    return count;
}

void LinkedList::add() {
    if (head == NULL){
        head = new Node();  
    }
    else {
        Node *temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new Node();
    }
}

string LinkedList::isFree(){
    return head->getData();
}

#endif // "PA2_H"