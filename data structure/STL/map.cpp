#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    map<string, int> m;

    m.insert({"dev2", 124});
    m.insert(m.begin(), make_pair("dev", 12));
    m.insert(m.begin(), {"dev3", 142});
    
    auto it = m.begin();
    for (auto val : m)
    {
        cout << val.first << " " << val.second<< endl;
    }

    return 0;
}