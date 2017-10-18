#ifndef PA2_H
#define PA2_H

using namespace std;

//defining the Node structure
struct Node {
    string size;
    Node *next;
};

class LinkedList {
    private:
    Node *head;
    public:
        int size(void) {
            int count = 0;
            Node *temp = head;
        
            while (temp != NULL) {
                temp = temp -> next;
                count++;
            }
            return count; 
        }
};

#endif // "PA2_H"