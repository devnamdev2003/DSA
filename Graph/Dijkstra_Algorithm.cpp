#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;
    vector<pair<int, int>> adj[n]{
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{2, 6}, {3, 2}, {4, 3}}};
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j].first << "(" << adj[i][j].second << ")"
                 << "->";
        }
        cout << endl;
    }

    // for (int start = 0; start < n; start++)
    // {
    int start = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    vector<int> dist(n, INT16_MAX);
    minH.push({0, start});
    dist[start] = 0;
    while (minH.size() != 0)
    {
        auto current = minH.top();
        int d = current.first;
        int node = current.second;
        for (auto i : adj[node])
        {
            if (i.second + d < dist[i.first])
            {
                minH.push({(i.second + d), i.first});
                dist[i.first] = i.second + d;
            }
        }
        minH.pop();
    }
    cout << "start " << start << ": ";
    for (auto v : dist)
    {
        cout << v << " ";
    }
    cout << endl;
    // }
    return 0;
}