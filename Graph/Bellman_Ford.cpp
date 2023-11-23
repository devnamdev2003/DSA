#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n = 6;
    vector<vector<int>> nodes = {{3, 2, 6}, {5, 3, 1}, {0, 1, 5}, {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3},{5,0,-3}};
    vector<int> dis(n, INT32_MAX);
    int start = 0;
    dis[start] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto i : nodes)
        {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            if (dis[u] < INT32_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    for (auto v : dis)
    {
        cout << v << " ";
    }
    cout<<endl;
    // ! check negative cycle;
    for (auto i : nodes)
    {
        int u = i[0];
        int v = i[1];
        int w = i[2];
        if (dis[u] < INT32_MAX && dis[u] + w < dis[v])
        {
            cout << "present";
            return -1;
        }
    }
    return 0;
}