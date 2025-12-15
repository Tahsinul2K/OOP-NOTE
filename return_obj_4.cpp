#include<iostream>
using namespace std;

class who
{
    char c;

    public:
    void set(char x)
    {
        c = x;
        cout << "Constructing " << c << endl;
        return;
    }
    void show()
    {
        cout << c << endl;
        return;
    }

    ~who()
    {
        cout << c << " is being destroyed" << endl;
    }
};

who input(char a)
{
    who temp;

    temp.set(a);

    return temp;
}

int main()
{
    who o1;
    o1 = input('a');

    o1.show();

    return 0;
}