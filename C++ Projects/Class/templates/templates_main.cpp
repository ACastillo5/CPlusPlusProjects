#include <iostream>

using namespace std;


template<typename T>

T divide(T a, T b){
    T r;
    r = a / b;
    return r;
}
/*
double divide(double a, double b){
    double r;
    r = a / b;
    return r;
}
*/
int main(){
    int x = 5;
    int y = 2;
    
    double a = 5.0;
    double b = 2.0;
    
    cout << divide(x, y) << endl;
    cout << divide(a, b) << endl;
    
    return 0;
    
}
    