#include <iostream>

using namespace std;

int main(){
    const int BASE_STUDENT_ID = 80000000;
    const int MAX_STUDENTS = 1000;
    // name, id, grades/gpa
    string name[1000];
    int id[1000];
    double gpa[1000];
    
    int currentIndex = 0;
    
    string tempName, tempId, tempGpa;
    
    do{
        cout << "Enter the student name" << endl;
        getline(cin, tempName);
        
        cout << "Enter the student id" << endl;
        getline(cin, tempId);
        
        cout << "Enter the student gpa" << endl;
        getline(cin, tempGpa);
        
        name[currentIndex] = tempName;
        id[currentIndex] = 80000000 + currentIndex;
        gpa[currentIndex] = stod(tempGpa);
        
        currentIndex++;
        
        if (currentIndex >= MAX_STUDENTS){
            break;
        }
        
        cout << "Enter more student names? (y/n):" << endl;
        getline(cin, tempName);
    }while(tempName != "n");
    
    for(int i = 0; i < currentIndex; i++){
        cout << name[i] << endl;
        cout << id[i] << endl;
        cout << gpa[i] << endl;
    }
    
    
    return 0;
}