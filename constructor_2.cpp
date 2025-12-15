#include <iostream> //stopwatch
#include <ctime>
#include<string>
using namespace std;

class timer
{
    clock_t start, end;

public:
    timer();
    ~timer();
    void record_show()
    {
        end = clock();
        cout << (end - start) / CLOCKS_PER_SEC << " seconds have passed" << endl;
        start = clock();
    }
};
timer::timer()
{
    start = clock();
}
timer::~timer()
{
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << " seconds have passed "<< endl;
}
int sum(int a);

int main()
{
    timer watch;
    string a, b;
    getline(cin, a);
    watch.record_show();
    getline(cin, b);
    return 0;
}

