#include <iostream>

using namespace std;

class Object
{
    int *p;

public:
    Object()
    {
        cout << "In default" << endl;
        p = (int *)malloc(sizeof(int) * 1);
        *p = 0;
    }
    Object(int a)
    {
        cout << "In param" << endl;
        p = (int *)malloc(sizeof(int) * 1);
        *p = a;
    }
    Object(Object &a)
    {
        cout << "In copy" << endl;
        p = (int *)malloc(sizeof(int) * 1);
        *p = *(a.p);
    }
    ~Object()
    {
        cout << "In destructor" << endl;
        free(p);
    }

    int get()
    {
        return *p;
    }
    void set(int a)
    {
        *p = a;
    }

    //Operator Overloading
    void operator=(const Object& rhs)
    {
        this->p = (int *)malloc(sizeof(int) * 1);
        *(this->p) = *(rhs.p);  
    }
};

Object negating(Object a)
{
    Object b;
    b.set(-(a.get()));

    return b;
}
int main()
{
    Object a(67);

    Object b;
    b = negating(a);
    /*negating(a) returns a temporary object; the default = sign does a shallow copy,
    so when the temp obj gets rekt,
    b gets a dangling pointer; we need to do a operator overloading for = sign */

    cout << "in  main " << b.get() << endl;
}