// // this is the basic logic, i donot know wheter the methametical formula
// // of calculating area is correct or not just trying to good my concepts.

// #include <iostream>

// using namespace std;

// int excpetionInchHandle(int *feet, int *inch)
// {
//     try
//     {
//         if (*inch > 11)
//             throw *inch;
//     }
//     catch (int inch1)
//     {
//         int feetAdd = inch1 / 12;
//         int inchAdd = inch1 % 12;
//         *feet += feetAdd;
//         *inch = inchAdd;
//     }
// }

// class Room
// {
// private:
//     int feet, inch;

// public:
//     float findParameter(int *feetObtain, int *inchObtain)
//     {
//         *feetObtain = *feetObtain * 2;
//         *inchObtain = *inchObtain * 2;
//         excpetionInchHandle(feetObtain, inchObtain);
//         feet = *feetObtain;
//         inch = *inchObtain;
//     }
//     float findArea(int feetLength, int inchLength, int feetWidth, int inchWidth)
//     {
//         feet = feetLength * feetWidth;
//         inch = inchLength + inchWidth;
//         try
//         {

//             if (inch > 11)
//                 throw inch;
//         }
//         catch (int inch1)
//         {
//             int feetAdd = inch1 / 12;
//             int inchAdd = inch1 % 12;
//             feet += feetAdd;
//             inch = inchAdd;
//         }
//     }
//     void dispParameter()
//     {
//         cout<<"Parameter are ..."<<endl;
//         cout << "Feet : " << feet << endl;
//         cout << "Inch : " << inch << endl;
//     }
//     void dispArea()
//     {
//         cout << "Area of the room is : " << feet << " feet and " << inch << " inches" << endl;
//     }
// };

// int main()
// {
//     int feetLenth, inchLength, feetWidth, inchWidth;
//     cout << "Enter legth of the room ... " << endl;
//     cout << "Enter feet : ";
//     cin >> feetLenth;

//     cout << "Enter Inches : ";
//     cin >> inchLength;
//     excpetionInchHandle(&feetLenth, &inchLength);
//     cout << "Enter Width of the room ... " << endl;
//     cout << "Enter feet : ";
//     cin >> feetWidth;
//     cout << "Enter Inches : ";
//     cin >> inchWidth;
//     excpetionInchHandle(&feetWidth, &inchWidth);
//     Room dining;
//   dining.findArea(feetLenth, inchLength, feetWidth, inchWidth);
//   dining.dispArea();
//   int addFeet,addInch;
//   addFeet=feetLenth+feetWidth;
//   addInch=inchWidth+inchLength;
//   dining.findParameter(&addFeet+feetWidth,&addInch);
//   dining.dispParameter();
//   return 0;
// }


// this is the new code 

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



