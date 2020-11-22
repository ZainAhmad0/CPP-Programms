
#include<iostream>

using namespace std;

class Dist
{
private:
        int feet;
        float inch;
public:
    void setFeet(int x)
    {
        feet=x;
    }
    void setInch(int x)
    {
        inch=x;
    }
    int getFeet()
    {
        return feet;
    }
    int getInch()
    {
        return inch;
    }
};

class Room
{
private:
    Dist length,width;
public:

    void setLength(int x,float y)
    {
        length.setFeet(x);
        length.setInch(y);
    }
    void setWidth(int x,float y)
    {
        width.setInch(y);
        width.setFeet(x);
    }
    int getLengthFeet()
    {
        return length.getFeet();
    }
    float getLengthInch()
    {
        return length.getInch();
    }
    float getWidthInch()
    {
        return width.getInch();
    }
    int getWidthFeet()
    {
        return width.getFeet();
    }
    Dist calculateArea(Room obj)
    {
        int feet=obj.getLengthFeet()*obj.getWidthFeet();
        float inches=obj.getWidthInch()*obj.getLengthInch();
        if(inches>=12)
        {
            int feetAdd = inches / 12;
            float inchAdd = int(inches) % 12;
            feet += feetAdd;
            inches = inchAdd;
        }
        Dist obj1;
        obj1.setFeet(feet);
        obj1.setInch(inches);
        return obj1;        
    }
    Dist calculatePara(Room obj)
    {
        int feet=(obj.getLengthFeet()+obj.getWidthFeet())*2;
        float inches=(obj.getWidthInch()+obj.getLengthInch())*2;
         if(inches>=12)
        {
            int feetAdd = inches / 12;
            float inchAdd = int(inches) % 12;
            feet += feetAdd;
            inches = inchAdd;
        }
        Dist obj1;
        obj1.setFeet(feet);
        obj1.setInch(inches);
        return obj1;  
    }  
};

int main()
{
    int feet;
    float inches;
    Room obj;
    cout<<"Enter lenth";
    cout<<"Feet : ";
    cin>>feet;
    cout<<"Inches : ";
    cin>>inches;
    obj.setLength(feet,inches);    
    cout<<"Enter Width";
    cout<<"Feet : ";
    cin>>feet;
    cout<<"Inches : ";
    cin>>inches;
    obj.setWidth(feet,inches);
    Dist obj1 = obj.calculateArea(obj);
    cout<<"Area "<<endl;
    cout<<"Feet : "<<obj1.getFeet()<<endl;
    cout<<"Inches : "<<obj1.getInch()<<endl;
    Dist obj2 = obj.calculatePara(obj);
    cout<<"Parameter "<<endl;
    cout<<"Feet : "<<obj2.getFeet()<<endl;
    cout<<"Inches : "<<obj2.getInch()<<endl;
    
}



