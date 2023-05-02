#include <iostream>
#include <vector>

using namespace std;

void dummy();
double average(vector<double> v);
void swap(double& a, double& b);

int main(){
    
    
    swap(x,y);
    
    cout << "x: " << x << " y: " << y << endl;
    
    vector<string> name;
    vector<int> id;
    vector<vector<double>> grades;
    
    name.push_back("Bob");
    id.push_back(800000001);
    vector<double> temp = {4.0, 3.0, 2.0, 3.0};
    grades.push_back(temp);
    
    name.push_back("Joe");
    id.push_back(800000002);
    vector<double> temp2 = {2.0, 2.0, 1.0, 3.0, 1.0, 2.0};
    grades.push_back(temp2);
    
    for(int i = 0; i < name.size(); i++){
        cout << name.at(i) << endl;
        cout << id.at(i) << endl;
        for (int j = 0; j < grades.at(i).size(); j++){
            cout << (grades.at(i)).at(j) << endl;
        }
        
        cout << average(grades.at(i)) << endl;
    }
    
    return 0;
}

void dummy(){
    vector<double> b = {44.0, 23.0, 22.0};
    cout << average(b) << endl;
}

double average(vector<double> v){
    double sum = 0.0;
    for (int i = 0; i < v.size(); i++){
        sum = sum + v.at(i);
    }
    double avg = sum / (double)v.size();
    return avg;
}

void swap(double& a, double& b){
    double temp = a;
    a = b;
    b = temp;
}