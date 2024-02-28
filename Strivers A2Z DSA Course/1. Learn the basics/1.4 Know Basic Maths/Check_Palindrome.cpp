#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n;
    cout << n;
    string str = to_string(n);
    int i = 0;
    int j = str.length() - 1;
    while (i <= j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    cout << ((i >= j) ? 1 : 0);

    return 0;
}