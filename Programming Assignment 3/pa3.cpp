#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

/*TODO:
    - Implement stacks for deteting each type of word we're looking for 
*/

#include "pa3.h"
using namespace std;
string checkInput(string Filename);
bool isNumber(int key);
bool isKeyword(int key);
bool isIdentifier(int key);
bool isDelimitier(int key);
bool isOperator(int key);
void printSet(set<string> &sets, string name);
vector<string> checkKeywords(Stack *keyword);

int main() {
    //char **words;
    string fileName = "input.txt";
    cout << "Please enter the name of the input file:" << endl;
    //cin >> fileName;

    //check for input
    fileName = checkInput(fileName);

    //Open the new file
    ifstream newFile;
    string line;
    set<string> identifiers;
    set<string> constants;
    set<string> keywords;
    set<string> delimitiers;
    set<string> operators;
    Stack *keywordStack = new Stack();

    //Identifies the types of input  
    newFile.open(fileName);
    if(newFile.is_open()){

        //Gets the first line of the document to analyze
        while ( getline (newFile,line) ){
            /*String for the different types we're looking for. Only the types that may contain more than 1 character
            are included here*/
            string identifier;
            string constant;
            string keyword;
            string operations;

            //Converts the line into a string stream
            istringstream iss(line);
            string word;

            //Goes through each word on the line that was gotten from getLine()
            while (iss >> word){
                for (int i = 0; i < word.length(); i++) {
                    //Checking if its a constant
                    if (isNumber(int(word[i]))){
                        cout << "word[i] is " << word[i] << endl;
                        constant += word[i];

                    //Checking if its a keyword
                    } else if (isKeyword(int(word[i]))){
                        cout << "word[i] is " << word[i] << endl;
                        keyword += word[i];

                    //Checking if its an operator
                    } else if (isOperator(int(word[i]))) {
                        cout << "word[i] is " << word[i] << endl;
                        operations += word[i];

                    //Checking if its a delimitier
                    } else if (isDelimitier(int(word[i]))) {
                        cout << "word[i] is " << word[i] << endl;
                        string delim;
                        delim += word[i];
                        delimitiers.insert(delim);

                    //Checking if its an identifier
                    } else if (isIdentifier(int(word[i]))) {
                        cout << "word[i] is " << word[i] << endl;
                        identifier += word[i];
                    }
                }
            }
            cout << "Inserted the words in each vector" << endl;
            identifiers.insert(identifier);
            constants.insert(constant);
            keywords.insert(keyword);
            operators.insert(operations);
            keywordStack->push(keyword);

            //Used for Printing the sets
            // printSet(identifiers, "Identifiers: ");
            // printSet(constants, "Constants: ");
            // printSet(keywords, "Keywords: ");
            // printSet(delimitiers, "Delimitiers: ");
            // printSet(operators, "Operators: ");
        }

    }
    newFile.close();

    return 0;
}

//Main Methods ---------------------------------------------------------
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
    return name;
}

bool isNumber(int key) {
    bool number = false;
    for (int i = 48; i < 58; i++){
        if (key == i) {
            number = true;
        }
    }
    return number;
}

bool isKeyword(int key) {
    bool keyword = false;
    for (int i = 65; i < 91; i++) {
        if (key == i) {
            keyword = true;
        }
    }
    return keyword;
}

bool isIdentifier(int key) {
    bool identifier = false;
    for (int i = 97; i < 123; i++) {
        if (key == i) {
            identifier = true;
        }
    }
    return identifier;
}

bool isDelimitier(int key) {
    return (key == 44 || key == 59) ? true : false;
}

bool isOperator(int key) {
    return (key == 42 || key == 43 || key == 45 || key == 47 || key == 61) ? true : false;
}

void printSet(set<string> &sets, string name) {
    cout << name;
    set<string>::iterator it; 
    for (it = sets.begin(); it != sets.end(); it++) {
        cout << *it;
    }
    cout << "\n";    
}

// vector<string> checkKeywords(Stack *keyword) {
//     vector<string> misSpelled;
//     int begin;
//     int end;
//     int FOR;

//     for (int i = 0; i < keyword->getSize(); i++){
//         string word = keyword->pop();
//         switch (word[i]) {
//             case 'E':
//                 begin++;
//                 if (word != "BEGIN"){
//                     misSpelled.push_back(word);
//                 }
//                 break;
//             case 'F':
//                 if (word != "FOR") {
//                     misSpelled.push_back(word);
//                 }
//                 break;
//             case 'B':
//                 if (word != "BEGIN"){
//                     misSpelled.push_back(word);
//                 }
//                 break;
//         }
//     }
//     return misSpelled;
// }
//-----------------------------------------------------------------------


//Stack Methods ---------------------------------------------------------
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
        cout << array[i] << " ";
    }
}

//Pop Method
string Stack::pop(){
    string element;
    if (array[0] == "NULL"){
        cout << "is null" << endl;
        return 0;
    }
    element = array[index];
    index--;
    return element;      
}

//Get Size Method
int Stack::getSize(){
    return size;
}
//-----------------------------------------------------------------------
