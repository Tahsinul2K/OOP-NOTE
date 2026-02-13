#include<iostream>
#include<string>
using namespace std;

class Message
{
    string message;
public:
    Message(string line){ this->message = line;}

    Message update(string line){ this->message = line; return *this;}
    void oy(string a)
    {
        this->message = a;
    }
    void show()
    {
        cout << message << endl;
    }
};

int main()
{
    Message o1("Hello");
    Message o2 = o1.update("NOWOWO");

    o1.show();
    o2.show();

    o2.oy("OY");
    o2.show();
    o1.show();
}