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
    pair<int, int> edge[] = {{1, 2}, {2, 1}, {1, 4}, {4, 2}, {4, 3}, {5, 5}, {3, 1}, {3, 5}};
    for (int i = 0; i < 8; i++)
    {
        v[edge[i].first].push_back(edge[i].second);
    }
    vector<int> visit(n + 1, 0);
    queue<pair<int, int>> q;
    q.push({1, 0});
    int target = 2;
    visit[q.front().first] = 1;
    while (q.size() != 0)
    {
        auto current = q.front();
        if (current.first == target)
        {
            cout << current.second << endl;
            break;
        }
        for (int i = 0; i < v[current.first].size(); i++)
        {
            if (visit[v[current.first][i]] == 0)
            {
                q.push({v[current.first][i], current.second + 1});
                visit[v[current.first][i]] = 1;
            }
        }
        q.pop();
    }
    if (q.size() == 0)
    {
        cout << -1;
    }
    return 0;
}