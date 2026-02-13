#include <iostream>
#include <string>
using namespace std; // Private members of parent can never be inherited by child, they stay in the parent class, and can be accessed by the methods of that class

class Parent
{
private:
    int age;
    string name;

public:
    Parent() { cout << "Parent Activated" <<endl; }
    Parent(int age, string name)
    {
        this->age = age;
        this->name = name;
        cout << "Parameter Parent Activated" <<endl;
    }
    string getName() { return this->name; }
    int getAge() { return this->age; }
};

class Child : public Parent
{
private:
    int dose;
    string hobby;

public:
    Child(string baby_name, int baby_age, int num, string hobby): Parent(baby_age, baby_name)
    {
        this->dose = num;
        this->hobby = hobby;
        cout << "Child Activated" <<endl;
    }
    int getDose() { return dose; }
    string getHobby() { return hobby; }
};

int main()
{
    //Parent dad(30, "John");
    Child son("Doe",7,3, "drawing");

    cout << son.getDose() << endl;


    return 0;
}