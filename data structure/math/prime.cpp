#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool prime(int n)
{
    int count = 0;
    if (n == 1)
    {
        return 0;
    }
    int i = 2;
    while (i * i <= n)
    {
        count++;
        if (n % i == 0)
        {
            return 0;
        }
        i++;
    }
    cout << count << endl;
    return 1;
}
void print(int n)
{
    for (int j = 2; j < n; j++)
    {
        if (prime(j))
        {
            cout << j << " ";
        }
    }
}
vector<int> print2(int n)
{
    float count = 0;
    vector<int> v;
    v.push_back(2);
    for (int i = 2; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < v.size(); j++)
        {
            count++;
            if (i % v[j] == 0)
            {
                break;
            }
        }
        if (j == v.size())
        {
            v.push_back(i);
        }
    }
    cout << n << ": " << count << " , " << count / n;
    cout << endl;
    return v;
}
void show_1d(vector<int> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1)
        {
            cout << v[i] << ",";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << "]";
    cout << endl;
}
bool prime2(int n)
{
    float count = 0;
    vector<int> v;
    v.push_back(2);
    for (int i = 2; i <= n; i++)
    {
        int j = 0;
        for (j = 0; j < v.size(); j++)
        {
            count++;
            if (i % v[j] == 0)
            {
                break;
            }
        }
        if (j == v.size())
        {
            v.push_back(i);
        }
    }
    cout << count / n;
    cout << endl;
    if (n == v[v.size() - 1])
    {
        return 1;
    }
    return 0;
}
int count_prime(int n)
{
    int count = 0;
    vector<bool> v(n + 1, 1);
    for (int i = 2; i < n; i++)
    {
        if (v[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
            {
                v[j] = 0;
            }
        }
    }
    return count;
}
int main()
{
    // for (int i = 9973; i < 10000; i++)
    // {
    //     cout << i << ": " << prime(i);
    //     cout << endl;
    // }
    // show_1d(print2(7));
    cout << count_prime(2 );
    // for (int i = 2; i < 12; i++)
    // {
    //     print2(i);
    // }
    // show_1d(print2(100));
    // show_1d(print2(1000));
    // show_1d(print2(10000));

    return 0;
}