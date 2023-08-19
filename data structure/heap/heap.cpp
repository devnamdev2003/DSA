#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    vector<int> v = {91, 2, 3, 22, 11, 64, 10};

    // todo max_heap
    priority_queue<int> max_heap;
    for (int i = 0; i < v.size(); i++)
    {
        max_heap.push(v[i]);
        if (max_heap.size() > v.size())
        {
            max_heap.pop();
        }
    }
    cout << max_heap.top() << endl;

    // todo min_heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < v.size(); i++)
    {
        min_heap.push(v[i]);
        if (min_heap.size() > v.size())
        {
            min_heap.pop();
        }
    }
    for (auto v : v)
    {
    }
    cout << min_heap.top() << endl;
    return 0;
}
