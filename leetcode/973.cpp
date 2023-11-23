#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
        int dis;
        for (int i = 0; i < points.size(); i++)
        {
            dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            min_heap.push({dis, {points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
        {
            int p = min_heap.top().second.first;
            int s = min_heap.top().second.second;
            ans.push_back({p, s});
            min_heap.pop();
        }
        return ans;
    }
};
void show_2d(vector<vector<int>> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution o;
    vector<vector<int>> v = {{3, 3}, {5, -1}, {-2, 4}};
    show_2d(o.kClosest(v, 2));

    return 0;
}