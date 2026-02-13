#include <iostream>
#include <string>
using namespace std; // method override //Parent class must have a default constructor

class A
{
    int x;

public:
    A() { cout << "Default A" << endl; }
    A(int x)
    {
        this->x = x;
        cout << "Param A" << endl;
    }

    void show()
    {
        cout << "show func of A class" << endl;
        cout << x;
    }
};

class B : public A
{
    int y;

public:
    B(int y, int x = 0): A(x)
    {
        this->y = y;
        cout << "B constructor has been called" << endl;
    }

    void show()
    {
        cout << "show func of B class" << endl;
        cout << y;
    }
};

int main()
{
    B ob1(56,98);
    ob1.A::show();
    return 0;
}