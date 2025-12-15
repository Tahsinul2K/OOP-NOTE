#include <iostream>
#include <cstdlib>

using namespace std;

class stack
{
    int tos;
    char *p;
    char who;
    int size_s;
public:
    stack(int size, char name);
    ~stack();
    char pop();
    void push(char x);
};
stack::stack(int size, char name)
{
    p = (char *)malloc(sizeof(char) * (size));
    who = name;
    tos = 0;
    size_s = size;
}

stack::~stack()
{
    cout << "exiting"<<endl;
    free(p);
}
void stack::push(char c)
{
    if(tos == size_s)
    {
        cout << who << " IS FULL" << endl;
    }
    else
    {
        p[tos] = c;
        tos++;
    }
}

char stack::pop()
{
    if (tos != 0)
    {
        tos--;
        char a = p[tos];
        return a;
    }
    else
    {
        cout << who << " IS EMPTY" << endl;
        return 0;
    }
}

int main()
{
    stack o1(3,'a'), o2(2,'b');

    o1.push('a');
    o1.push('y');
    o1.push('t');
    o1.push('m');
    char l1 = o1.pop();

    o2.push('z');
    o2.push('x');
    o2.push('b');
    char l2 = o2.pop();
    char l3 = o2.pop();

    cout << l1 << l2 << l3 << " popped items";
}