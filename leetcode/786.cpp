#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<float, pair<int, int>>> max_heap;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                max_heap.push({float(arr[i]) / float(arr[j]), {arr[i], arr[j]}});
                if (max_heap.size() > k)
                {
                    max_heap.pop();
                }
            }
        }
        int f = max_heap.top().second.first;
        int s = max_heap.top().second.second;
        return {f, s};
    }
};
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
int main()
{
    Solution o;
    vector<int> v = {1, 2, 3, 5};
    show_1d(o.kthSmallestPrimeFraction(v, 3));
    return 0;
}