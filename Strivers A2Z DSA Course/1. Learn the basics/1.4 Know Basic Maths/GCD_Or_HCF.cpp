#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int i, j;
    cin >> i >> j;
    int mn = min(i, j);
    int mx = max(i, j);
    while (true)
    {
        int r = mx % mn;
        if (r == 0)
        {
            cout << mn;
            break;
        }
        mx = mn;
        mn = r;
    }

    return 0;
}