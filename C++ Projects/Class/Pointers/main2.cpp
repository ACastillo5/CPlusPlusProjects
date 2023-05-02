#include <iostream>

using namespace std;

class MyVector{
    public:
    MyVector(){
        nextIdx = 0;
        arraySize = 3;
        a = new int[arraySize];
    }
    
    MyVector(const MyVector& rhs){
        cout << "Copy Constructor Called!" << endl;
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new int[arraySize];
        for (int i = 0; i < nextIdx; i++){
            a[i] = rhs.a[i];
        }
    }
    
    ~MyVector(){
        cout << "Destructor Called!\n" << endl;
        delete[] a;
    }
    
    void operator=(const MyVector& rhs){
        cout << "Assignment Operator Override Called!" << endl;
        delete[] a;
        
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new int[arraySize];
        for (int i = 0; i < nextIdx; i++){
            a[i] = rhs.a[i];
        }
    }
    
    void push_back(int val){
        if(nextIdx == arraySize){
            cout << "Reallocating more space..." << endl;
            int* temp = new int[arraySize*2];
            for(int i = 0; i < arraySize; i++){
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
            arraySize = arraySize * 2;
        }
        
        a[nextIdx] = val;
        nextIdx++;
    }
    
    void pop_back(){
        nextIdx--;
    }
    
    int at(int idx){
        return a[idx];
    }
    
    int size(){
        return nextIdx;
    }
    
    int* a;
    
    private:
    int nextIdx;
    int arraySize;
};

void makesProblem(){
    MyVector v;
    
    v.push_back(10);    
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);    
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v.pop_back();
    v.pop_back();
    
    v.push_back(20);
    
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    MyVector v2;
    v2.push_back(10);    
    v2.push_back(8);
    v2.push_back(5);
    v2.push_back(7);

    v2 = v;
    
    
    for (int i = 0; i < v.size(); i++){
        cout << v2.at(i) << endl;
    }
    
    MyVector v3 = v;
    
    cout << "End of Function Called!" << endl;
}


int main(){
    
    makesProblem();
    
    makesProblem();
    
    makesProblem();
    
    return 0;
}