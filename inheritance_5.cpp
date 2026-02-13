#include<iostream>
using namespace std;

class Base
{
    public:
    virtual void show()
    {
        cout << "this is Base class"<<endl;
    }
};
class Derived : public Base
{
    public:
    void show()
    {
        cout<< "this is derived class"<<endl;
    }
};



int main()
{
    Base* ptr;
    Derived d;
    ptr = &d;
    ptr->show(); //Derived show
    ptr->Base::show(); // Base show

    Derived* ptr2;
    Derived d2;
    ptr2=&d2;
    ptr2->show(); //Derived show()
    ptr2->Base::show(); //Base show()
    return 0;
}