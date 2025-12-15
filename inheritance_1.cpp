#include <iostream>
using namespace std;
class B
{
    int i;

public:
    void input_i(int x);
    int get_i();
}; // does inheritance transfer constructor destructor?
void B::input_i(int x)
{
    i = x;
}
int B::get_i()
{
    return i;
}

class D : public B
{
    int j;

public:
    void input_j(int x);
    int get_j();
    int add();
};
void D::input_j(int x)
{
    j = x;
}
int D::get_j()
{
    return j;
}
int D::add()
{
    return get_i() + j;
}

int main()
{
    D o1;
    B o2;

    o1.input_i(23);
    o1.input_j(67);

    int sum = o1.add();

    cout << sum << endl;

    return 0;
}