#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
string checkInput(string Filename);

int main() {
    string fileName;
    cout << "Please enter the name of the input file:" << endl;
    cin >> fileName;

    //check for input
    fileName = checkInput(fileName);

    ifstream newFile;
    newFile.open(fileName);


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
    }
    cout << "File openned sucessfully" << endl;
    newFile.close();
    return name;
}
