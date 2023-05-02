/*
Adrian Castillo-Navarro
This program will compute the number of routes through an n x n grid
The user is prompted enter an integer to make a n x n grid (n is the integer they inputted)
The output will be the amount of routes it will take to 
go from the top left of the grid to the bottom left of the grid
If the number is 0, it exits the code immediately
If the number is not 0, it does the calculation to calculate the routes
*/

#include <iostream>

using namespace std;

int main(){
    
    //This will be the integer the user will input into
    int n;
    
    //Asking the user what number to input
    cout << "What n x n grid would you like to create: ";
    cin >> n;
    
    //If  user inputs 0, code automatically ends
    if (n == 0){
        cout << "Not possible.\nExitting..." << endl;
        exit(0);
    }
    
    //This calculates the routes able to be taken
    else{
        //There will be at least one route
        //The unsigned int will not allow any overload to occur
        long double Routes = 1;
        
        for (int i = 0; i < n; i++) {
            
            //The type of permutation needed is nCr
            
            //Both of these are the n parts of nCr
            long double a = (2 * n) - i;
            Routes = Routes * a;
            
            //This is the r part of the nCr
            long double b = i + 1;
            Routes = Routes / b;
            
        }
        
        cout << "With a " << n << " x " << n << " grid...\nThere are " << Routes << " route(s)." << endl;
    }
    
    return 0;
}