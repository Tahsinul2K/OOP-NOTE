#include<iostream>
#include<vector>
using namespace std;

class samp
{
    int a;
    vector<int> arr;

    public:
    void input(int a)
    {
        this->a = a;
        arr.resize(a);

        for(int i = 0 ; i < a ; i++)
        {
            printf("enter value of a[%d]: ",i);
            cin >> arr[i];
        }
    }
    void show()
    {
        for(int i = 0 ; i < a ; i++)
        {
            printf("value of a[%d]: ",i);
            cout << arr[i] << endl;
        }
        return;
    }
};
int main()
{
    samp o1, o2;
    int x;
    cin >> x;
    o1.input(x);

    o2 = o1;

    o2.show();
    return 0;
}