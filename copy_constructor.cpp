#include<iostream>
#include<string>
using namespace std;

class Profile
{
    private:
    string name;
    int id;

    public:
    Profile(string name , int id)
    {
        this-> name = name;
        this-> id = id;
    }

    Profile(Profile& ob)
    {
        this-> name = ob.name;
        this-> id = ob.id;
    }
    string getName()
    {
        return name;
    }
    int getID()
    {
        return id;
    }
};

int main()
{
    Profile ob1("arefeen", 2405108);
    Profile ob2(ob1);

    cout<<ob2.getName() << " " << ob2.getID() <<endl; 
}