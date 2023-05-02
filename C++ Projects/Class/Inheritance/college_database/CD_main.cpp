#include <iostream>

using namespace std;

class Person{
   public:
   
   Person(string name, int id){
       this->name = name;
       this->id = id;
   }
   
   void setName(string name){
       this->name = name;
   }
   
   string getName() const{
       return name;
   }
   
   void setId(int id){
       this->id= id;
   }
   
   int getId() const{
       return id;
   }
   
   void Print(){
       cout << name << " " << id << endl;
   }
   
   protected:
   string name;
   int id;
};

class Student : public Person{
    public:
   
    Student(string name, int id, double gpa) : Person(name, id){
        this->gpa = gpa;
    }
   
    void setGpa(double gpa){
        if(gpa >= 0.0 && gpa <= 4.0){
            this->gpa = gpa;
        }
    }
   
    double getGpa() const{
        return gpa;
    }
   
    void Print(){
        cout << name << " " << id << " " << gpa << endl;
    }
   
    private:
    double gpa;
};

class Faculty : public Person{
    public:
    Faculty(string name, int id, double salary) : Person(name, id){
        this->salary = salary;
    }
   
    void setSalary(double salary){
        this->salary = salary;
    }
   
    double getSalary() const{
        return salary;
    }
   
    /*void Print(){
        cout << name << " " << id << " " << salary << endl;
    }*/
   
    private:
    double salary;
};

int main(){
   
    Student s("Sam", 800234123, 2.8);
    //s.setName("Sam", 800234123, 2.8);
    //s.setId(800234123);
    //s.setGpa(2.8);
    Faculty f("George", 12843758, 65000);
   
    s.Print();
    f.Print();
   
   
   
    return 0;
}