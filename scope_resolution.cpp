#include<iostream>
using namespace std;

class X
{
    public:
    static int count;
};
int X::count = 10; //a non static member can not be defined outside, for a static variable member in a class, the memory is allocated beforehand and that memory space is shared by all the objects of that class

int main()
{
    X ob1, ob2;
    cout << "the value of ob1 count is: " << ob1.count <<endl;
    cout << "incrementing the count by onein ob2: " << ++ob2.count <<endl;
    cout<< "the count in ob1 has also changes: " <<ob1.count <<endl;
    return 0;
}