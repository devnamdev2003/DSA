#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 0, 11, 64, 10};
    vector<int> ans;
    int k = 3;
    // todo min_heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < v.size(); i++)
    {
        min_heap.push(v[i]);
        if (min_heap.size() > 3)
        {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
    }
    while (min_heap.size() > 0)
    {
        ans.push_back(min_heap.top());
        min_heap.pop();
    }
    for (auto v : ans)
    {
        cout << v << " ";
    }
    // cout << min_heap.top() << endl;
    return 0;
}
