#include <iostream>
#include <string.h>
#include <cstdlib>
#include "pa2.h"

using namespace std;

/* TODO:
    -Implement initialization. Only one node is getting the "FREE" identifier
    -Work on printing the node list
*/


//Functions
//void initializeList(LinkedList *list);
void MainMenu(string fit);

int main(int argc, char **argv) {

    string fit = argv[1];
    int choice = 0;    
    //MainMenu(fit);
    LinkedList *availableList = new LinkedList("FREE");

    for(int i = 0; i < 31; i++){
        availableList->add();        
    }
    int size = availableList->size();
    cout << size << endl;
    
}


// void initializeList(LinkedList *list) {
//     for(int i = 0; i < 31; i++){
//         list->add();
//     }
// }

void MainMenu(string fit){
    string status = fit;

    cout << "Using " << fit << " algorithm:" << endl;

    int choice = 0;
    while(choice !=5){
        //error checking
        do {
            cout << "1. Add program \n" << "2. Kill program \n" << "3. Fragmentation \n" << "4. Print memory \n" << "5. Exit" <<endl;
            cin >> choice;
            if (choice < 1 || choice > 5) {
                cout << "Error, invalid input. Please try again" << endl;                
            }
            
        } while (choice < 1 || choice > 5);

        //selection 
        string name;
        switch (choice) {
            //Adding a Program
            case 1:
                cout << "Choice - " << choice << endl;
                //Program Name
                cout << "Program Name - ";
                cin >> name;

                //Program Size
                int size;
                cout << "Program Size (KB) - ";
                cin >> size;
                break;

            case 2:
                cout << "Choice - " << choice << endl;
                break;
            
            case 3:
                cout << "Choice - " << choice << endl;
                break;
                
            case 4:
                cout << "Choice - " << choice << endl;
                break;
                
            case 5:
                cout << "Choice - " << choice << endl;
                break;
        }
    }
}