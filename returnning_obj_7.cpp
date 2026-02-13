#include <iostream>
#include <string>
using namespace std;
/*
VVI: when you return an object from a function, the return statement calls the copy constructor,
if you have written deep copy constructor, no worries even if the local variable gets destroyed in the function
because the copying happens first.

otherwise it will be a problem. Always implement deep copy if your class owns dynamic memory

So i will always write a copy / deep copy constructor (depending on the situation) when I need to write a
function that returns an object.
*/
class Member
{
    string name;
    int age;

public:
    Member()
    {
        name = "";
        age = -1;
    }
    Member(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    Member(Member &m)
    {
        this->name = m.name;
        this->age = m.age;
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
};
class Party
{
    Member *array[100];
    int count = 0;
    string name;

public:
    Party(string name = "")
    {
        this->name = name;
        count = 0;
    }
    Party(Party &obj)
    {
        this->name = obj.name;
        this->count = obj.count;
        for (int i = 0; i < obj.count; i++)
        {
            this->array[i] = new Member(*obj.array[i]);
        }
    }
    ~Party()
    {
        for (int i = 0; i < count; i++)
            delete array[i];
    }
    void join(Member m)
    {
        array[count] = new Member(m);
        count++;
    }

    Party form_new_party(string name_party)
    {
        Party local;
        local.name = name_party;
        int j = 0;
        for (int i = 0; i < this->count; i++)
        {
            if (this->array[i]->getAge() < 18)
            {
                (local.array[j]) = new Member(*(this->array[i]));
                j++;
            }
        }
        local.count = j;
        return local;
    }
    void show_all()
    {
        cout << "MEMBERS OF " << this->name << endl
             << endl;
        for (int i = 0; i < this->count; i++)
        {
            cout << "Name: " << array[i]->getName() << ", Age: " << array[i]->getAge() << endl;
        }
        cout << endl;
        return;
    }
};

int main()
{
    Member araf("araf", 10);
    Member tahs("tahs", 67);
    Member nigga("nigga", 89);
    Member lol("lol", 78);
    Member afreen("afreen", 10);

    Party all("all");
    all.join(araf);
    all.join(tahs);
    all.join(nigga);
    all.join(lol);
    all.join(afreen);
    all.show_all();

    Party under = all.form_new_party("under");

    under.show_all();
}