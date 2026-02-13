#include <iostream>
// someone can pass a obj to function in 2 ways:
/*
1. By reference
2. By value (Copy constructor shits asbe)
*/

using namespace std;

class ObArg
{
    int *p;

public:
    ObArg(int a)
    {
        cout << "in constructor" << endl;
        p = (int *)malloc(sizeof(int) * 1);
        *p = a;
    }
    //Copy Constructor: if you did NOT write a copy constructor, the compiler generates a default copy constructor(SHALLOW COPY!!!!)
    ObArg(ObArg& a)
    {
        cout << "in copy constructor"<<endl;
        p = (int *)malloc(sizeof(int) * 1);
        *p = *(a.p);
    }

    ~ObArg()
    {
        cout << "in destructor" << endl;
        free(p);
    }

    int get()
    {
        return *p;
    }
};

int negative(ObArg obj) //if there is a copy constructor then it will call the copy constructor and make a deep copy for the local variable
{
    return -(obj.get());
}

int main()
{
    ObArg x(23);

    cout<<"in main"<< endl << negative(x) <<endl;
}