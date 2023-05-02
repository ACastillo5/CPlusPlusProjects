#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));
    int r = rand() % 3;
    
    string userInput;
    string userQuestion;
    char dummy;
    
    do {
        cout << "Ask the magic 8-ball a question." << endl;
        getline(cin, userQuestion);
        cin.ignore(999);
        cin.clear();
        
        int r = rand() % 4;
    
         switch(r){
            case(0):
                cout << "Yes" << endl;
                break;
            case(1):
                cout << "No" << endl;
                break;
            case(2):
                cout << "Maybe" << endl;
                break;
            case(3):
                cout << "I wouldn't count on it" << endl;
                break;
            default:
                cout << "Error" << endl;
            
        }
        
        cout << "Do you want to ask another question? (Yes/No)" << endl;
        cin >> userInput;
        
    } while(userInput == "Yes");
    
    
    
    /*
    if(r == 0){
        cout << "Yes" << endl;
    } else if (r == 1){
        cout << "No" << endl;
    } else if (r == 2){
        cout << "Maybe" << endl;
    } else {
        cout << "Unexpected Input" << endl;
    }
    */
    return 0;
}