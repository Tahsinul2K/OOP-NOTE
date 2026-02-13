#include <iostream>
#include <string>
using namespace std;
/*

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

    void set_name(string name)
    {
        this->name = name;
    }
    void set_age(int age)
    {
        this->age = age;
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

    Member& get_person_with_age(int newage)
    {
        for(int i = 0 ; i<count ; i++)
        {
            if(array[i]->getAge() == newage)
            {
                return *(array[i]);
            }
        }
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

    Member& get_age_10 = all.get_person_with_age(10);

    get_age_10.set_name("HIHIHIH");

    all.show_all();
}