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
        LinkedList(string status);
        string status();
        void print();
        void initialize();
        
};

LinkedList::LinkedList(string status){
    head = new Node();
    head->data = status;
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

string LinkedList::status(){
    return head->getData();
}

void LinkedList::print(){
    Node *temp = head;
    int counter = 0;
    while (temp -> next !=NULL){
        if (counter % 8 == 0) {
            cout << "\n";
        }
        cout << temp->getData() << "\t";
        temp = temp -> next;
    }
}

#endif // "PA2_H"