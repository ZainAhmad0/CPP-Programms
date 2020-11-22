#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;

public:
    Shape(int, int);
    virtual int getArea();
};
int Shape ::getArea()
{
    return 0;
}
Shape ::Shape(int a = 0, int b = 0)
{
    width = a;
    height = b;
}
class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
    int getArea();
};
int Rectangle ::getArea()
{
    return width * height;
}
class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}
    int getArea();
};
int Triangle ::getArea()
{
    return (width * height / 2);
}

int main()
{
    Shape *obj;
    Rectangle objRec(10, 7);
    Triangle objTri(10, 5);
    obj = &objRec;
    cout << "Area of Rectablge : " << obj->getArea() << endl;
    obj = &objTri;
    cout << "Area of Triangle : " << obj->getArea() << endl;
    return 0;
}