#include <iostream>
using namespace std;
void fun1(int n, int m)
{
    if (n == 0)
    {
        return;
    }
    cout << "*";
    fun1(n - 1, m + 1);
    if (m > 0)
    {
        return;
    }
    cout << endl;
    fun1(n - 1, 0);
}

void fun2(int r, int c)
{
    if (r == 0)
    {
        return;
    }
    cout << "*";
    if (c == r)
    {
        cout << endl;
        r = r - 1;
        c = 0;
    }
    fun2(r, c + 1);
}

int main()
{
    // fun1(5, 0);
    fun2(5, 3);

    return 0;
}