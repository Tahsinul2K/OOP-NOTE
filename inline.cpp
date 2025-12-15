#include<iostream>
using namespace std;

class samp
{
    private:
    int i,j;

    public:
    samp(int i, int j)
    {
        this->i = i;
        this->j = j;
    }
    int divisibility();
};

inline int samp:: divisibility()
{
    if(i%j == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    samp o1(4,2), o2(2,3);
    cout << o1.divisibility() << " " << o2.divisibility() << endl;
    return 0;
}