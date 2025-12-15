#include<iostream>
#include<string>
using namespace std;

class profile
{
    private:
    string name;
    int age;
    int level;

    public:
    profile(string x, int y, int z); //constructor must have the same name as the class; no return type
    void show()
    {
        cout << name << " " << age << " " << level << endl;
    }
    ~profile();
};
profile:: ~profile()
{
    age = 0;
    level = 0;
    cout << name << " " << age << " " << level << endl;
}

profile:: profile(string x, int y, int z)
{
    name = x;
    age = y;
    level = z;
}

int main()
{
    profile o1("arefeen", 21, 67);

    o1.show();
    cout << "nigga boy" << endl;
    return 0;
}
