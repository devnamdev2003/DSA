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
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    cout << ((n == 0) ? 1 : count);
    return 0;
}