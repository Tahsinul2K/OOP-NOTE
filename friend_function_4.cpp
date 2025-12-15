#include <iostream>

using namespace std;
class pr2;
class pr1
{
    int printing;
    
public:
    pr1() { printing = 0; }
    void set_print(int status) { printing = status; }
    friend bool inuse(pr1 a, pr2 b);
};
class pr2
{
    int printing;
    
public:
    pr2() { printing = 0; }
    void set_print(int status) { printing = status; }
    friend bool inuse(pr1 a, pr2 b);
};

bool inuse(pr1 a, pr2 b)
{
    bool x = a.printing + b.printing;
    return x;
}

int main()
{
    pr1 o1; pr2 o2;

    o1.set_print(0);

    cout << inuse(o1, o2) << endl;

    o2.set_print(0);

    cout << inuse(o1, o2) << endl;
    return 0;
}