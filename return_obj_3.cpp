#include<iostream>

using namespace std;

class samp
{
    int a;

    public:
    ~samp()
    {
        cout<< "bye" << endl;
    }
    void get_a(int a)
    {
        this->a = a;
        return;
    }
    void show()
    {
        cout << a <<endl;
    }
};

samp input(int x)
{
    samp temp1;
    temp1.get_a(x);

    return temp1;
}

int main()
{
    samp o1;

    o1 = input(6);

    return 0;
}