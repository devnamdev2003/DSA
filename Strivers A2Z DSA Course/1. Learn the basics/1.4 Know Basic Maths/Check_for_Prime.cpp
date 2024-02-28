#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        if (i * i >= n)
        {
            break;
        }
    }
    int j;
    for (j = 2; j <= i; j++)
    {
        if ((n % j) == 0)
        {
            cout << "not number ";
            break;
        }
    }
    if (j > i)
    {
        cout << "prime number";
    }
    return 0;
}