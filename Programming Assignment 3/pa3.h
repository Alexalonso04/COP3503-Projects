#ifndef PA3_H
#define PA3_H
#include <string.h>

using namespace std;

class Stack {
    string *array;
    int size;
    int index;

    public:
    Stack();
    void push(string a);
    void print();
    string pop();
    int getSize();
};

#endif // "PA3_H"
