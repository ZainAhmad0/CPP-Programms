#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;

// function prototypes
void nextStep(int count, int *nextStepDirection, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30]);
// giving direction to the control to where to head next in order to maintain and print the shape
void stepRight(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30]);
void stepUp(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30]);
void stepDown(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30]);
void stepLeft(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30]);
// after every changings in the 2D array to make it look like firework printArr function is frequently called
// and the printArr funciton prints all the 2D array simply of the simple conditions 
// if the array location contains -1 then it would print dot else it would print space, hence maintaining the shape 
void printArr(int coordinates[20][30]);
// resetArray function is actually intializing the array with 0 intitally.
void initializeArray(int coordinates[20][30]);

void printstar(int stars = 3) // default parameter is used here
// stars = 3 means that only 3 stars would be printed by default
// and if user is passing any argument in this function than that particular number of stars would be printed hence not making it hard coded
{
    int space = 60; // this is to define appropriate space where stars would be printed to maintian the spiral shape
    for (int i = 0; i < stars; i++)
    {
        cout << setw(space) << "." << endl;
        space = space - 2;
        usleep(200000);
    }
}

int main()
{
    cout << setw(50) << endl;
    cout << "Group Members : Miral Fatima_20I-0844" << setw(50) << endl;
    cout << "                AEIMAN IMTIAZ_20i-0757" << setw(50) << endl;
    cout << "                SANA FATIMA_20I-0658" << setw(50) << endl;

    cout << "                       ------------------------------------------" << setw(50) << endl;
    cout << "FIREWORKS PROJECT" << setw(50) << endl
         << endl
         << endl;
    cout << "Press any character to Print Spiral" << endl;
    char t;
    cin >> t;
    int nextStepDirection = 1;
    int cursorXPosition = 10;
    int cursorYPosition = 10;
    int coordinates[20][30];
    cursorXPosition = 12;
    cursorYPosition = 12;
    initializeArray(coordinates); // this is to initialize the whole array to 0
    coordinates[cursorXPosition][cursorYPosition] = -1;
    for (int a = 1; a <= 10; a++)
    {
        nextStep(a, &nextStepDirection, &cursorXPosition, &cursorYPosition, coordinates);
    }
    printArr(coordinates);
    printstar();
    cout << endl;
    return 0;
}

void nextStep(int count, int *nextStepDirection, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30])
{
    switch (*nextStepDirection)
    {
    case 1:
        stepRight(count, cursorXPosition, cursorYPosition, coordinates);
        *nextStepDirection = 2;
        break;

    case 2:
        stepDown(count, cursorXPosition, cursorYPosition, coordinates);
        *nextStepDirection = 3;
        break;

    case 3:
        stepLeft(count, cursorXPosition, cursorYPosition, coordinates);
        *nextStepDirection = 4;
        break;

    case 4:
        stepUp(count, cursorXPosition, cursorYPosition, coordinates);
        *nextStepDirection = 1;
        break;

    default:
        break;
    }
}

void stepRight(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30])
{
    for (int i = 0; i < count; i++)
    {
        *cursorYPosition += 2;
        if (i != count - 1)
        {
            coordinates[*cursorXPosition][*cursorYPosition] = -1;
        }
        printArr(coordinates);
        usleep(200000);
    }
}

void stepUp(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30])
{
    for (int i = 0; i < count; i++)
    {
        *cursorXPosition = *cursorXPosition - 1;
        if (i != count - 1)
        {
            coordinates[*cursorXPosition][*cursorYPosition] = -1;
        }
        printArr(coordinates);
        usleep(200000);
    }
}

void stepDown(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30])
{
    if (count == 10) 
    /* 
    This is bacause on the end interation of main for loop the control will end the 
    spiral shape on this funciton at count value 10, so for the last iteration we want to 
    print 12 instead of 10 dots to make it look like spiral
    */
    {
        count = count + 1;
    }
    
    for (int i = 0; i < count; i++)
    {
        *cursorXPosition = *cursorXPosition + 1;
        if (i != count - 1)
        {
            coordinates[*cursorXPosition][*cursorYPosition] = -1;
        }
        printArr(coordinates);
        usleep(200000);
    }
}

void stepLeft(int count, int *cursorXPosition, int *cursorYPosition, int coordinates[20][30])
{
    for (int i = 0; i < count; i++)
    {
        *cursorYPosition -= 2;
        if (i != count - 1)
        {
            coordinates[*cursorXPosition][*cursorYPosition] = -1;
        }
        printArr(coordinates);
        usleep(200000);
    }
}

void printArr(int coordinates[20][30])
{
    system("clear");  // to make it show like firework 
    static int maxValueOfXDimension = 18;
    static int maxValueOfYDimension = 30;
    /* 
    beacuse printArr function is frequently invoked everytime when we
    invoke the function because of their static behavior they donot get changed
    when the new function call is arrived. the value for  maxValueOfXDimension and maxValueOfYDimension
    will remain same for all the funciton calls for this particular funtion 
    */

    for (int i = 0; i < maxValueOfXDimension; i++)
    {
        cout<<setw(40);
        for (int j = 0; j < maxValueOfYDimension; j++)
        {
            char ch = (coordinates[i][j] != 0) ? '.' : ' ';
            cout << ch;
        }
        cout << endl;
    }
}

void initializeArray(int coordinates[20][30])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            coordinates[i][j] = 0;
        }
    }
}
