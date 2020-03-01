//OOP Assignment # 1
//Muhammad Saad      01-131192-020
//Zain Ahmad         01-131192-037
//Date : 02 March 2020

/*
//friend function
#include<iostream>
using namespace std;
class SetValues
{
private:
	float length, width, height;
public:
	SetValues()
	{
		length = 0;
		width = 0;
		height = 0;
	}

    void setParameters(float takeLength,float takeWidth ,float takeHeight)
    {
        length=takeLength;
        width=takeWidth;
        height=takeHeight;
    }

    float getLength()
    {
        return length;
    }

    float getWidth()
    {
        return width;
    }

    float getHeight()
    {
        return height;
    }
	friend float findVolume(SetValues obj);
    friend float findSurfaceArea (SetValues obj);
};

float findVolume(SetValues obj)
{
    return obj.height * obj.length * obj.width; // volume = length * width * height
}

float findSurfaceArea (SetValues obj)
{
    //surface area = 2(length*width)+2(width*heigth)+2(height*length)
    return 2 * (obj.length * obj.width) + 2 * (obj.width * obj.height) + 2 * (obj.height * obj.length);
}

int main()
{
	int choice=0;
    float length, width, height;
    SetValues obj;
    cout<<"1: Find Volume of the Cube/Cuboid "<<endl;
    cout<<"2: Find Surface Area of Cube/Cuboid "<<endl;
    cout<<endl<<"Please enter your choice : ";
    cin>>choice;
    if(choice==1||choice==2)
    {
    cout << "Enter the Length of the Cube/Cuboid in meteres: ";
	cin >> length;
	cout << "Enter the width of the Cube/Cuboid in meteres: ";
	cin >> width;
	cout << "Enter the Height of the Cube/Cuboid in meteres: ";
	cin >> height;
    obj.setParameters(length,width,height);
    }
    switch (choice)
    {
    case 1:
    {
        cout << "Volume of the Cube/Cuboid is " <<findVolume(obj)<<" meter cube "<<endl;
        cout<<"Where"<<endl<<"Length = "<<obj.getLength()<<" , Width = "<<obj.getWidth()<<" , Height = "<<obj.getHeight()<<endl;
        break;
    }
    case 2:
    {
        cout <<"Surface Area of Cube/Cuboid is " << findSurfaceArea (obj) << " meter square "<<endl;
        cout<<"Where"<<endl<<"Length = "<<obj.getLength()<<" , Width = "<<obj.getWidth()<<" , Height = "<<obj.getHeight()<<endl;
        break;
    }

    default:
    {
        cout<<"Sorry, Invalid Choice Entered "<<endl;
        break;
    }
    }
	return 0;
}

*/
// friend class
/*
#include<iostream>
using namespace std;

class SetParameters
{
private:
    float height,mass,velocity,gravity;
public:
    SetParameters()
    {
        height = 0;
        mass = 0;
        velocity = 0;
        gravity = 9.8;
    }

    void setParameters(float takeMass,float takeVelocity,float takeHeight)
    {
        mass=takeMass;
        velocity=takeVelocity;
        height=takeHeight;
    }

    float getMass()
    {
        return mass;
    }

    float getVelocity()
    {
        return velocity;
    }

    float getHeight()
    {
        return height;
    }
    friend class FindValueOfEnergies;

};

class FindValueOfEnergies
{
public:
    float findKineticEnergy(SetParameters obj)
    {
        // kinetic energy = (mass * (velovity * velocity)) / 2;
        float kineticEnergy =  ((obj.mass)*(obj.velocity*obj.velocity));
        kineticEnergy=kineticEnergy/2;
        return kineticEnergy;
    }
    float findPotentialEnergy(SetParameters obj)
    {
        // potential energy = mass * height * gravity
        float potentialEnergy =  ((obj.mass)*(obj.gravity)*(obj.height));
        return potentialEnergy;
    }
};

int main()
{
    float height,mass,velocity;
    int choice;
    SetParameters obj;
    FindValueOfEnergies obj1;
    cout<<"1: Find Kinetic Energy "<<endl;
    cout<<"2: Find Potential Energy "<<endl;
    cout<<endl<<"Please enter your choice : ";
    cin>>choice;
    if(choice==1||choice==2)
    {
        cout << "Enter veloity in metere per second: ";
        cin >> velocity;
        cout << "Enter mass in kilogram (kg): ";
        cin >> mass;
        cout << "Enter the Height in meteres: ";
        cin >> height;
        obj.setParameters(mass,velocity,height);
    }
    if(choice==1)
    {
        cout<<"Kinetic Energy is "<<obj1.findKineticEnergy(obj)<<" joules "<<endl;
        cout<<"Where"<<endl<<"Mass = "<<obj.getMass()<<" , velocity = "<<obj.getVelocity()<<endl;
    }
    else if (choice==2)
    {
        cout<<"Potential Energy is "<<obj1.findPotentialEnergy(obj)<<" joules "<<endl;
        cout<<"Where"<<endl<<"Mass = "<<obj.getMass()<<" , Height = "<<obj.getHeight()<<endl;
        // gravity is constant and is equal to 9.8 meter per second square
    }
    else
    {
        cout<<"Sorry, Invalid choice entered "<<endl;
    }
    return 0;
}
*/



