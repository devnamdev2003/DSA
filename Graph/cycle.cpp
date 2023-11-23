#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;

bool isCycle(int V, vector<int> adj[])
{
    vector<int> visit(V + 1, 0);
    queue<int> q;
    int start = 1;
    q.push(start);
    while (q.size() != 0)
    {
        int current = q.front();
        visit[current] = 2;
        for (auto i : adj[current])
        {
            if (visit[i] == 0)
            {
                q.push(i);
                visit[i] = 1;
            }
            else
            {
                if (visit[i] == 2)
                {
                    continue;
                }
                else
                {
                    return 1;
                }
            }
        }
        q.pop();
    }
    return 0;
}
bool is_cycle(vector<int> v[], int n)
{
    vector<int> visit(n + 1, 0);
    queue<int> q;
    int start = 1;
    q.push(start);
    while (q.size() != 0)
    {
        int current = q.front();
        visit[current] = 2;
        for (auto i : v[current])
        {
            if (visit[i] == 0)
            {
                q.push(i);
                visit[i] = 1;
            }
            else
            {
                if (visit[i] == 2)
                {
                    continue;
                }
                else
                {
                    return 1;
                }
            }
        }
        q.pop();
    }
    return 0;
}
int main()
{
    int n = 4;
    vector<int> v[n + 1];
    pair<int, int> edge[] = {{2, 1}, {1, 4}, {2, 3}};
    for (int i = 0; i < 3; i++)
    {
        v[edge[i].first].push_back(edge[i].second);
        v[edge[i].second].push_back(edge[i].first);
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << "->";
        }
        cout << endl;
    }

    vector<int> store;
    cout << boolalpha;
    cout << is_cycle(v, n) << endl;
    return 0;
}