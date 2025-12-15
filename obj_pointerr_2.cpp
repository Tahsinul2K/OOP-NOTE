#include<iostream>

using namespace std;

class samp
{
    int i,j;

    public:
    samp(int x, int y)
    {
        i = x;
        j = y;
    }
    int get_i()
    {
        return i;
    }
    void show()
    {
        cout << i << " " << j << endl;
        return;
    }
};

void update(samp& x)
{
    
}