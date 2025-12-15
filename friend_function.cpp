#include<iostream>

using namespace std;
class truck;

class car
{
    int speed, p;

    public:
    car(int speed, int p)
    {
        this->speed = speed;
        this->p = p;
    }

    friend int compare(car a, truck b);
};

class truck
{
    int speed, p;

    public:
    truck(int speed, int p)
    {
        this->speed = speed;
        this->p = p;
    }

    friend int compare(car a, truck b);
};

int compare(car a, truck b)
{
    if(a.speed > b.speed)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    car o1(30,3); truck o2(20,7);

    int x = compare(o1, o2);

    cout << x;
    return 0;

}