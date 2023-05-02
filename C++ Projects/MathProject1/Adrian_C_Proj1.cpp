/*
Adrian Castillo-Navarro
This program uses the Collatz Sequence,
The user is prompted to enter a number
That number will multiply the number by 3 and then add 1 if it is odd
If the number is even the number will be divided by 2
This goes on until the number is 1


*/
#include <iostream>

using namespace std;

int main(){
    
    unsigned int x;
    int n = 1;
    
    //The user is asked what number to enter
    cout << "Please choose a number to use the Collatz Sequence: " << endl;
    
    cin >> x;
    
    //This prints the number the user entered
    cout << x << " -> ";
    
    //This while loop allows the number to keep being 
    //multiplied or divided until the number is less
    // than or equal to 1
    while (x > 1){
        
        //This checks if the number is even if the 
        // remainder is 0
        if (x % 2 == 0){
            
            //Because the number is even it is 
            // being divided by 2
            x = x / 2;
            cout << x << " -> ";
            n = n + 1;
            
            //This continue function allows the 
            // program to start again from the while loop
            continue;
        }
        //This checks if the number is odd if the 
        // remainder is 1
        if (x % 2 == 1){
            
            //This number is odd, so it is multiplied
            // by 3 and added by 1
            x = (3*x) + 1;
            cout << x << " -> ";
            n = n + 1;
            //This continue function allows the 
            // program to start again from the while loop
            continue;
        }
    }
    
    cout << "Done!" << endl;
    cout << "The length of the sequence is: " << n << endl;

    return 0;
}