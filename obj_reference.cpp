#include <iostream>
#include <string>

using namespace std;

/*
Never return a reference to a local variable, it causes dangling problems.
*/

class Member
{
    int age;
    string name;

public:
    Member(string name, int age)
    {
        this->name;
        this->age = age;
    }

    string &get_OG_Name() { return name; }
    int &get_OG_Age() { return age; }
    void show()
    {
        cout <<"Name: " <<name <<", Age: " << age <<endl;
    }
};

int main()
{
    Member p1("Arefeen",21);

    string& name_ref = p1.get_OG_Name();
    int& age_ref = p1.get_OG_Age();

    name_ref = "HI";
    age_ref = 86487;

    p1.show();

}
