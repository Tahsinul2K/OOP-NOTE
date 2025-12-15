#include<iostream>
#include<cstring>

using namespace std;

class Student
{
    char *name;
    int marks;

    public:
    Student(char* n, int m)
    {
        name = new char[strlen(n) + 1]; // we mallocate memory for name
        strcpy(name, n);
        marks = m;
    }
    Student(const Student &s) // Copy constructor for deep copy
    {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        marks = s.marks;
    }
    ~Student()
    {
        delete[] name;
    }
    void display()
    {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }
};

int main()
{
    Student s1("Alice", 90);
    s1.display();

    // Copying object s1 to s2
    Student s2(s1); // Calls copy constructor

    s2.display();

    return 0;
}