#include <iostream>

using namespace std;

class Shape {
    public:
    Shape(double height, double width){
        this->height = height;
        this->width = width;
    }
    
    void print(){
        cout << "Should not be called!" << endl;
    }
    
    protected:
    double height;
    double width;
    
};

class Triangle : public Shape {
    
    public:
    Triangle(double height, double width) : Shape(height, width) { }
    
    void print(){
        cout  << "Triangle \nHeight: " << height << " Base: " << width << endl;
    }
    
    double getArea(){
        return 0.5 * height * width;
    }
};

class Rectangle : public Shape {
    public:
    Rectangle(double height, double width) : Shape(height, width) { }
    
    void print(){
        cout << "Rectangle \nHeight: " << height << " Width: " << width << endl;
    }
    
    double getArea(){
        return height * width;
    }
};

class Square : public Rectangle {
    public:
    Square(double width) : Rectangle(width, width) { }
    
    void print(){
        cout << "Square \nHeight: " << height << " Width: " << width << endl;
    }
};

int main(){
    
    Rectangle r (5, 10);
    Triangle t (5, 7);
    Square s (10);
    
    r.print();
    cout << "Area: " << r.getArea() << endl << endl;
    
    t.print();
    cout << "Area: " <<  t.getArea() << endl << endl;
    
    s.print();
    cout << "Area: " <<  s.getArea() << endl << endl;
    
    return 0;
}