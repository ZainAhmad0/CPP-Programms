#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int arr[10];
class calculator
{
private:
        int take1, take2;
        int sum;

public:
        calculator()
        {
                cout << "Default constructor is executed perfectly" << endl;
                take1 = 0;
                take2 = 0;
                for (int i = 0; i < 10; i++)
                {
                        arr[i] = (rand() % 105) + (rand() % 3);
                        cout << arr[i] << "   ";
                }
                cout << endl;
                sum = 0;
        }

        ~calculator()
        {
                for (int i = 0; i < 10; i++)
                {

                        cout << arr[i] << "   ";
                }
                cout << "\nDefault destructor is executed perfectly" << endl;
        }

        int add()
        {
                for (int i = 0; i < 10; i++)
                {
                        sum += arr[i];
                }
                return sum;
        }
};

void finder(int aa = 0)
{

        for (int i = aa + 1; i < 10; i++)
        {
                if (arr[aa] < arr[i])
                {
                        int temp;
                        temp = arr[aa];
                        arr[aa] = arr[i];
                        arr[i] = temp;
                }
        }
        if (aa == 9)
                return;

        finder(aa + 1);
}

int main()
{
        calculator a;

        finder();
        cout << endl
             << endl
             << endl;

  
}
