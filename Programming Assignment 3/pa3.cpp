#include <iostream>
#include <string.h>
#include <fstream>

#include "pa3.h"
using namespace std;
string checkInput(string Filename);

int main() {
    string fileName;
    cout << "Please enter the name of the input file:" << endl;
    cin >> fileName;

    //check for input
    fileName = checkInput(fileName);

    //Open the new file
    ifstream newFile;
    newFile.open(fileName);

    cout << "Enter a couple of numbers for our stack" << endl;
    string number;
    Stack *numberStack = new Stack();
    for (int i = 0; i < 3; i++) {
        cin >> number;
        numberStack->push(number);
    }
    numberStack->print();

    cout << "Let's pop the first one now" << endl;
    cout << numberStack->pop() << endl;



    return 0;
}

string checkInput(string fileName) {
    ifstream newFile;
    string name = fileName;
    newFile.open(name);
    while (!(newFile.is_open())){
        cout << "Error, file not found" << endl;
        cout << "Please enter the correct file name, ending with .txt " << endl;
        cin >> name;
        newFile.open(name);
    }
    cout << "File openned sucessfully" << endl;
    newFile.close();
    return name;
}


//Stack Methods

//Constructor
Stack::Stack() {
    size = 20;
    index = 0;
    array = new string[20];
}

//Push method
void Stack::push(string a){
    if ((index + 1) == size) {
        string *newArray = new string[size * 2];
            for (int i = 0; i < size; i++){
                newArray[i] = array[i];
            }
        array = newArray;
        size = size * 2;    
    }
    index++;
    array[index] = a;
}

//Print Method
void Stack::print() {
    for (int i = 0; i < index + 1; i ++) {
        cout << array[i] << endl;
    }
}

//Pop Method
string Stack::pop(){
    string element;
    if (array[0] == "NULL"){
        return 0;
    }
    element = array[index];
    index--;
    return element;      
}