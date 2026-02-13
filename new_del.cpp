#include<iostream>
using namespace std;
class Point
{
    int x,y;
    public:
    Point(){x=0; y=0;}

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void set(int a, int b)
    {
        x= a;
        y = b;
    }
    int mult()
    {
        return x*y;
    }
};

int main()
{
    Point* ptr = new Point(6,7);
    Point* r = new Point[2]; //if default constructor was not present, this wouldnt have worked

    for(int i = 0 ; i < 2 ; i++)
    {
        r[i].set(i+2, i*3); 
        //(r+i)->set(i+2,i*3);
    }
    cout << ptr->mult() << endl;
    cout << r->mult() << endl;
    cout << (r+1)->mult() << endl;

    delete []r;
    delete ptr;
    return 0;
}