#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

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
    vector<string> identifiers;
    vector<string> constants;
    vector<string> keywords;
    vector<string> delimitiers;
    vector<string> operators;


    //Identifies the types of input  
    newFile.open(fileName);
    if(newFile.is_open()){

        while ( getline (newFile,line) ){
            string identifier;
            string constant;
            string keyword;
            string operators;
            string delimitiers;

            istringstream iss(line);
            string word;
            while (iss >> word){
                for (int i = 0; i < word.length(); i++){
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
                        operators += word[i];

                    //Checking if its a delimitier
                    } else if (isDelimitier(int(word[i]))) {
                        cout << "word[i] is " << word[i] << endl;
                        delimitiers += word[i];

                    //Checking if its an identifier
                    } else if (isIdentifier(int(word[i]))) {
                        cout << "word[i] is " << word[i] << endl;
                        identifier += word[i];
                    }
                }
            }
            cout << "Identifier: " << identifier << endl;
            cout << "Constant: " << constant << endl;
            cout << "Keyword: " << keyword << endl;
            cout << "Operators: " << operators << endl;
            cout << "Delimitiers: " << delimitiers << endl;
        }
    }  
    newFile.close();

    return 0;
}

//Main Methods
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

//Determine of the character is a number 
// bool isConstant(string key) {

//     cout << key << endl;

//     // stringstream st;
//     // st << key;
//     // float number = 0;
//     // bool isNumber = true;

//     // st >> number;
//     // if (st.good()){
//     //     isNumber = false;
//     // } else if (number == 0 && key[0] != '0'){
//     //     isNumber = false;
//     // } else {
//     //     isNumber = true;
//     // }

//     return isNumber;
// }

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
