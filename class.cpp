#include <iostream>
using namespace std;
#define SIZE 10
class stack
{
private:
    char arr[SIZE];
    int tos = 0;

public:
    void push(char a)
    {
        if (tos == SIZE)
        {
            cout << "stack is full" << endl;
        }
        else
        {
            arr[tos] = a;
            tos++;
        }
    }

    char pop()
    {
        if (tos == 0)
        {
            cout << "Cant pop" << endl;
            return 0;
        }
        else
        {
            tos--;
            return arr[tos];
        }
    }
    void printing();
};
void stack::printing()
{
    for (int i = 0; i < tos; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    stack o1;
    o1.push('a');
    o1.push('e');
    o1.push('i');
    o1.push('o');
    o1.push('u');

    o1.printing();
    cout << o1.pop() << " the prev got rekt" << endl;
    cout << o1.pop() << " the prev got rekt" << endl;
    return 0;
}