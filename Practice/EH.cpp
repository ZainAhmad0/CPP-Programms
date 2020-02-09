// exception handling example
#include <iostream>
#include <string>
using namespace std;
int x=-1;
int main()
{
    try
    {
        try
        {
            try
            {
                if(x<0)
                throw 'z';
                else 
                throw 102;
                
            }
            catch(char a)
            {
               cout<<"Came in string"<<endl;
               throw; // it means now the arg which is accepted woule be throwed to the catch block of the outer try..
            }
            catch (int t)
            {
                cout<<"Default Exception"<<endl;
                throw 10;
            }
            
            
        }
        catch (char q)
        {
            cout << "Handle Partially "<<endl;
           throw; //Re-throwing an exception
        }
    }
    catch (char r)
    {
        cout << "Handle remaining "<<endl;
    }
    cout<<"After all try-catch blocks..."<<endl;
    return 0;
}