#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    vector<int> v = {
        1,
        2,
        3,
        4,
        5,
    };
    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });

    rotate(v.begin(), v.begin()+v.size()-1, v.end());
    cout<<endl;
    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });

    return 0;
}