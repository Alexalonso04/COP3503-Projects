#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include "pa2.h"

/*
//Name: Alejandro Alonso
//UFID: 3635-5787
//Assignment 2
//Date: 10/15/2017
*/


using namespace std;

/* TODO:
*/

/*STATUS:
*/


//Functions
void initializeList(LinkedList *list);
void MainMenu(string fit, LinkedList *list);
int checkInput();
void addProgram(string fit, LinkedList *list);
void spaceAvailable(LinkedList *list);

int main(int argc, char **argv) {

    if (argc != 2) {
        cout << "Usage ./<program>.out [worst/best]";
    }

    //Initialize LinkedList to 32 available nodes
    LinkedList *availableList = new LinkedList("FREE");
    initializeList(availableList);

    //User's choice for best or worst fit algorithm
    string fit = argv[1];

    //Main Menu for the program
    MainMenu(fit, availableList);

}

void initializeList(LinkedList *list) {
    //Adds 32 nodes to the linked list
    for(int i = 0; i < 32; i++){
        list->add();        
    }
}

void MainMenu(string fit, LinkedList *list){
    
    //Type of Algorithm selected by the users
    string status = fit;
    cout << "Using " << fit << " fit algorithm:" << endl;

    int choice = 0;
    while(choice !=5) {
        //Error checking
        choice = checkInput();

        //Selection 
        string name;
        int fragments;
        switch(choice) {
            //Add a Program
            case 1:
                cout << "Choice - " << choice << endl;
                addProgram(fit, list);
                break;
                
            //Kill a Program
            case 2:
                cout << "Choice - " << choice << endl;
                cout << "Program name - ";
                cin >> name;

                list->remove(name);
                break;
            
            //Display Fragmentation
            case 3:
                cout << "Choice - " << choice << endl;
                fragments = list->fragmentationStatus();
                cout << "There are " << fragments << "(s) fragments." << endl;
                break;
            
            //Print Memory
            case 4:
                cout << "Choice - " << choice << endl;
                list->print();
                break;
                
            //Exit Program
            case 5:
                cout << "Choice - " << choice << endl;
                break;    
        }
    }    
}

int checkInput(){
    int choice = 0;
    do {
        cout <<"\n" << "1. Add program \n" << "2. Kill program \n" << "3. Fragmentation \n" << "4. Print memory \n" << "5. Exit" <<endl;                    
        if(!(cin >> choice)){
            cin.clear(); //Clear the input stream
            cin.ignore(999, '\n');
            //cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore input that doesn't math the input type or exceeds the maximum input values accepted
            cout << "Error, invalid input. Please try again " << endl;
        } else if (choice < 1 || choice > 5) {
            cout << "Error, invalid input. Please try again " << endl;                
        }
    } while (choice < 1 || choice > 5);
    return choice;
}

void addProgram(string fit, LinkedList *list){
    string name;
    int size;
        //Program Name
        cout << "Program Name - ";
        cin >> name;

        //Program size
        cout << "Program Size (KB) - ";
        cin >> size;

        list -> insert(size, name, fit);
}

