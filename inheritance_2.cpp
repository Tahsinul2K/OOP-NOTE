#include <iostream>
using namespace std;

class area_cl
{
public:
    double height;
    double width;
};

class rectangle: public area_cl
{
    public:
    rectangle(double x, double y)
    {
        height = x;
        width = y;
    }
    double area();
};
double rectangle:: area()
{
    return height * width;
}

class isosceles: public area_cl
{
    public:
    isosceles(double x, double y)
    {
        height = x;
        width = y;
    }
    double area_tri();
};
double isosceles:: area_tri()
{
    return (height * width)/2 ;
}

int main()
{
    rectangle o1(5,6);
    isosceles o2(4,7);

    cout << o1.area() << endl;
    cout << o2.area_tri() << endl;

    return 0;
}