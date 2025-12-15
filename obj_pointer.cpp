#include<iostream>
using namespace std;

class myclass
{
    int i;

    public:
    myclass(int i)
    {
        this->i = i;
    }
    int get_i()
    {
        return i;
    }
};

int main()
{
    myclass o1(5), o2(67);

    myclass* p = &o1;

    cout << p->get_i() << endl;

    p = &o2;

    cout << p->get_i() << endl;
}