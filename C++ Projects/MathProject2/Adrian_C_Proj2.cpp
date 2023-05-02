/*
Adrian Castillo-Navarro
This program uses the Euclidean Algorithm
The user is prompted to enter two numbers
That number will be divided and the remainder will be given
If the remainder isn't 0, the while loop will keep running until it does
When the number is 0, the penultimate remainder is given as the GCD
*/

#include <iostream>

using namespace std;

int main(){
    
    //Integers a and b will be used to input the numbers
    int a;
    int b;
    
    //The variable to be used to output the GCD
    int c;
    
    //The user is asked what two numbers to enter for the GCD
    cout << "What two numbers would you like to find the GCD of?" << endl;
    cout << "The first number: ";
    cin >> a;
    
    cout << "The second number: ";
    cin >> b;
    
    //These temp variables will be used to have the numbers keep being changed without 
    // affecting the a and b variables
    int temp1 = a;
    int temp2 = b;
    
    //This temp variable will be used to hold the remainder
    int temp3 = temp1 % temp2;
    
    //This outputs what two numbers are being divided first
    cout << endl << temp1 << " / " << temp2 << " Remainder: " << temp3 << endl;
    
     //This while loop keeps going until the remainder is 0
    while (temp3 > 0){
        
        //Changes the first number to the second number
        temp1 = temp2;
        
        //Changes the second number to the remainder
        temp2 = temp3;
        
        //Remainder when both numbers are divided
        temp3 = temp1 % temp2;
        
        //Outputs what is going on with each time the while loop runs
        cout << temp1 << " / " << temp2 << " Remainder: " << temp3 << endl;
    }
    
    //The c variable is now the penultimate remainder
    c = temp2;
    
    //Outputting the GCD
    cout << endl;
    cout << "The GCD of (" << a << "," << b << ")" << " is " << c << endl;
    
    return 0;
}