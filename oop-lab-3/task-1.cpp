#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
    double width;
    double height;
};

class Rectangle: public Shape{
public:
    Rectangle(double h, double w){
        height = h;
        width = w;
    }

    void displayHeight(){
        cout << "The height of the rectangle is: " << height << endl;
    }

    void displayWidth(){
        cout << "The width of the rectangle is: " << width << endl;
    }

    double areaOfRectangle(){
        double area;
        area = height * width;
        return area;
    }
};

int main(){
    Rectangle r1(5,10);
    r1.displayHeight();
    r1.displayWidth();
    cout << "The area of the rectangle is: " << r1.areaOfRectangle() << endl;
    return 0;
}