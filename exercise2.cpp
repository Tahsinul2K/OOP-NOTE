#include<iostream>
#include<string>

using namespace std;
class card
{
    private:
    string book, author;
    int num;

    public:
    void store(string x, string y, int z = 0);
    void show();
};

void card:: store( string x, string y, int z)
{
    book = x;
    author = y;
    num = z;
}

void card:: show()
{
    cout << book << " " << author << endl << num << endl;
}

int main()
{
    card o1;
    o1.store("Harry Potter", "J.K. Rowlings");
    o1.show();
}