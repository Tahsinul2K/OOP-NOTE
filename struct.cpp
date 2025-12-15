#include <iostream>
#define SIZE 2
using namespace std;

struct stack
{
    stack(char who);
    void push(char x);
    char pop();

private:
    char s[SIZE];
    int tos = 0;
    char who;
};
stack::stack(char who)
{
    this->who = who;
}
void stack::push(char x)
{
    if (tos == SIZE)
    {
        cout << "stack full" << endl;
        return;
    }
    else
    {
        s[tos] = x;
        tos++;
    }
}
char stack:: pop()
{
    if(tos == 0)
    {
        cout << who << " stack empty" << endl;
        return 0;
    }
    else 
    {
        tos--;
        return s[tos];
    }
}

int main()
{
    stack o1('a'), o2('b');
    o1.push('k');
    o1.push('i');
    o1.push('u');
    cout << o1.pop() << endl;
    cout << o2.pop() << endl;
}