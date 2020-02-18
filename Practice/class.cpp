// this is the basic logic, i donot know wheter the methametical formula
// of calculating area is correct or not just trying to good my concepts.

#include <iostream>

using namespace std;

int excpetionInchHandle(int *feet, int *inch)
{
    try
    {
        if (*inch > 11)
            throw *inch;
    }
    catch (int inch1)
    {
        int feetAdd = inch1 / 12;
        int inchAdd = inch1 % 12;
        *feet += feetAdd;
        *inch = inchAdd;
    }
}

class Room
{
private:
    int feet, inch;

public:
    float findParameter(int *feetObtain, int *inchObtain)
    {
        *feetObtain = *feetObtain * 2;
        *inchObtain = *inchObtain * 2;
        excpetionInchHandle(feetObtain, inchObtain);
        feet = *feetObtain;
        inch = *inchObtain;
    }
    float findArea(int feetLength, int inchLength, int feetWidth, int inchWidth)
    {
        feet = feetLength * feetWidth;
        inch = inchLength + inchWidth;
        try
        {

            if (inch > 11)
                throw inch;
        }
        catch (int inch1)
        {
            int feetAdd = inch1 / 12;
            int inchAdd = inch1 % 12;
            feet += feetAdd;
            inch = inchAdd;
        }
    }
    void dispParameter()
    {
        cout<<"Parameter are ..."<<endl;
        cout << "Feet : " << feet << endl;
        cout << "Inch : " << inch << endl;
    }
    void dispArea()
    {
        cout << "Area of the room is : " << feet << " feet and " << inch << " inches" << endl;
    }
};

int main()
{
    int feetLenth, inchLength, feetWidth, inchWidth;
    cout << "Enter legth of the room ... " << endl;
    cout << "Enter feet : ";
    cin >> feetLenth;

    cout << "Enter Inches : ";
    cin >> inchLength;
    excpetionInchHandle(&feetLenth, &inchLength);
    cout << "Enter Width of the room ... " << endl;
    cout << "Enter feet : ";
    cin >> feetWidth;
    cout << "Enter Inches : ";
    cin >> inchWidth;
    excpetionInchHandle(&feetWidth, &inchWidth);
    Room dining;
  dining.findArea(feetLenth, inchLength, feetWidth, inchWidth);
  dining.dispArea();
  int addFeet,addInch;
  addFeet=feetLenth+feetWidth;
  addInch=inchWidth+inchLength;
  dining.findParameter(&addFeet,&addInch);
  dining.dispParameter();
  return 0;
}
