#include<iostream>
using namespace std;

class myclass
{
    int a;
    int arr[2];

    public:
    void input()
    {
        cout << "enter the val a: " << endl;
        cin >> a;
        for(int& x : arr)
        {
            static int i = 0;
            printf("enter the value of a[%d]: ", i);
            cin >> x;
            i++;
        }
    }
    void show()
    {   
        cout << "Output:"<< endl << a << endl;
        for(int x:arr)
        {
            cout << x << " ";
        }
    }
};
int main()
{
    myclass o1,o2;
    o1.input();

    o2 = o1;

    o2.show();
    return 0;
}