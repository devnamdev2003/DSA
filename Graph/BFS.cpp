#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n = 5;
    vector<int> v[n + 1];
    pair<int, int> edge[] = {{2, 1}, {1, 3}, {2, 5}, {4, 5}, {3, 4}, {4, 2}};
    for (int i = 0; i <= n; i++)
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

    vector<int> visit(n + 1, 0);
    queue<int> q;
    vector<int> store;
    q.push(1);
    visit[q.front()] = 1;
    while (q.size() != 0)
    {
        for (int i = 0; i < v[q.front()].size(); i++)
        {
            if (visit[v[q.front()][i]] == 0)
            {
                q.push(v[q.front()][i]);
                visit[v[q.front()][i]] = 1;
            }
        }
        store.push_back(q.front());
        q.pop();
    }
    for (auto i : store)
    {
        cout << i << " ";
    }
    return 0;
}