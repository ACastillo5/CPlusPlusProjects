#include <iostream>

using namespace std;


int main(){
    
    int x = 5;
    int* p = &x;
    *p = 10 + p;
    
    return 0;
}