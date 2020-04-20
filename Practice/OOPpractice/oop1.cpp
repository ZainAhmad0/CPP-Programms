#include <iostream>
using namespace std;

class Counter
{
protected:
    int count;

public:
    Counter()
    {
        count = 2;
    }
    Counter(int c)
    {
        count = c;
    }
    int getCount()
    {
        return count;
    }
    void operator++()
    {
        ++count;
    }
};

class CountDn : public Counter
{
public:
    void operator--()
    {
        --count;
    }
};
int main()
{
    CountDn c1;
    ++c1;
    ++c1;
    ++c1;
    cout <<"c1 = "<< c1.getCount();
    --c1;
    --c1;
    cout << endl<<"c1 ="<< c1.getCount();
    return 0;
}