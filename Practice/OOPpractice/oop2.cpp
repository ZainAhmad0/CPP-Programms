#include <iostream>

using namespace std;

class Shape
{
protected:
    float width;
    float height;
public:
    void setWidth(float w)
    {
        width = w;
    }
    void setHeight(float h)
    {
        height = h;
    }
};
class Rectangle : public Shape
{
public:
    float getAreaRectangle()
    {
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    float getAreaTrianlge()
    {
        return ((width * height)/2);
    }
};

int main()
{
    Rectangle obj;
    Triangle obj1;
    obj1.setHeight(4.5);
    obj1.setWidth(5.4);
    obj.setWidth(5);
    obj.setHeight(7.2);
    cout << "Total area of rectangle: " << obj.getAreaRectangle() << endl;
    cout << "Total area of Tritangle: " << obj1.getAreaTrianlge() << endl;
    return 0;
}