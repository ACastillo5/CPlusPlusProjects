#include <iostream>
#include <vector>

using namespace std;

class Student {
    
    public:
    
    Student(string n, int i, vector<double> g){
        cout << "Constructor called!" << endl;
        
        name = n;
        setId(i);
        
        for(int i = 0; i < g.size(); i++){
            addGrade(g.at(i));   
        }
    }
    
    Student(string n, int i) : name(n){
        cout << "Constructor called!" << endl;
        setId(i);
    }
    
    Student(){
        name = "Undefined";
        id = -1;
    }
    
    void setName(string n){
        name = n;
    }
    
    string getName() const {
        return name;
    }
    
    void addGrade(double g){
        if (g > 4.0 || g < 0.0){
            cout << "That's a problem, you just put an invalid grade" << endl;
            return;
        }
        
        grades.push_back(g);
    }
    
    vector<double> getGrades(){
        return grades;
    }
    
    void setId(int x){
        if (x > 80000000){
            id = x;
        }
        else{
            cout << "You put an invalid ID" << endl;
            id = -1;
        }
    }
    
    int getId() const {
        return id;
    }
    
    double getGpa(){
        if (grades.size() == 0){
            return 4.0;
        }
        
        
        double sum = 0.0;
        for (int i = 0; i < grades.size(); i++){
            sum = sum + grades.at(i);
            return sum/(double)grades.size();
        }
    }
    
    private:
    string name;
    int id;
    vector<double> grades;
};


int main(){
    
    vector <Student> students(5);
    
    
    vector<double> temp = {4.0, 3.0, 2.0, 33.0};
    Student s("Bob", 80000001, temp);
    //s.setName("Bob");
    //s.setId(80000001);
    //s.addGrade(3.0);
    //s.addGrade(4.0);

    students.push_back(s);

    Student s1("Joe", 7, temp);
    //s1.setName("Joe");
    //s1.setId(7);
    //s1.addGrade(3.0);
    //s1.addGrade(6.0);
    
    students.push_back(s1);
    
    Student s2("Mary", 80000002);
    
    students.push_back(s2);
    
    for(int i = 0; i < students.size(); i++){
        cout << students.at(i).getName() << endl;
        cout << students.at(i).getId() << endl;
        cout << students.at(i).getGpa() << endl;
    }
        
    return 0;
}

