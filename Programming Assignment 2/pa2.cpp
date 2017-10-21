#include <iostream>
#include <string.h>
#include <cstdlib>
#include "pa2.h"

using namespace std;

/* TODO:
    -Design a function to insert programs in memory
    -Implement best and worst fit algorithms
*/


//Functions
void initializeList(LinkedList *list);
void MainMenu(string fit);
int checkInput();

int main(int argc, char **argv) {

    //Initialize LinkedList to 32 available nodes
    LinkedList *availableList = new LinkedList("FREE");
    initializeList(availableList);

    //User's choice for best or worst fit algorithm
    string fit = argv[1];

    //Main Menu for the program
    MainMenu(fit);

}


void initializeList(LinkedList *list) {
    for(int i = 0; i < 32; i++){
        list->add();        
    }
}

void MainMenu(string fit){
    
    //Type of Algorithm selected by the users
    string status = fit;
    cout << "Using " << fit << " algorithm:" << "\n" << endl;

    int choice = 0;
    while(choice !=5) {
        //Error checking
        choice = checkInput();

        //Selection 
        string name;
        switch(choice) {
            //Add a Program
            case 1:
                if (fit == "best"){
                    cout << "Choice - " << choice << endl;
                    //Program Name
                    cout << "Program Name - ";
                    cin >> name;

                    //Program Size
                    int size;
                    cout << "Program Size (KB) - ";
                    cin >> size;

                    
                } else if (fit == "worst"){

                }
                break;
                
            //Kill a Program
            case 2:
                cout << "Choice - " << choice << endl;
                break;
            
            //Display Fragmentation
            case 3:
                cout << "Choice - " << choice << endl;
                break;
            
            //Print Memory
            case 4:
                cout << "Choice - " << choice << endl;
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
        cout << "1. Add program \n" << "2. Kill program \n" << "3. Fragmentation \n" << "4. Print memory \n" << "5. Exit" <<endl;
        cin >> choice;
        if (choice < 1 || choice > 5) {
            cout << "Error, invalid input. Please try again" << endl;                
        }
    } while (choice < 1 || choice > 5);
    return choice;
}