#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0},
                                {1, 1, 0, 0},
                                {0, 0, 1, 1}};
    vector<vector<int>> visit = {grid.size(), vector<int>(grid[0].size(), 0)};
    vector<vector<int>> dist = {grid.size(), vector<int>(grid[0].size(), 0)};
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    while (q.size() != 0)
    {
        auto current = q.front();
        int i = current.first.first;
        int j = current.first.second;
        int d = current.second;
        visit[i][j] = 1;
        if (i + 1 < visit.size())
        {
            if (grid[i + 1][j] != 1 && visit[i + 1][j] == 0)
            {
                q.push({{i + 1, j}, d + 1});
                dist[i + 1][j] = d + 1;
                visit[i + 1][j] = 1;
            }
        }
        if (i - 1 >= 0)
        {
            if (grid[i - 1][j] != 1 && visit[i - 1][j] == 0)
            {
                q.push({{i - 1, j}, d + 1});
                dist[i - 1][j] = d + 1;
                visit[i - 1][j] = 1;
            }
        }
        if (j + 1 < visit[i].size())
        {
            if (grid[i][j + 1] != 1 && visit[i][j + 1] == 0)
            {
                q.push({{i, j + 1}, d + 1});
                dist[i][j + 1] = d + 1;
                visit[i][j + 1] = 1;
            }
        }
        if (j - 1 >= 0)
        {
            if (grid[i][j - 1] != 1 && visit[i][j - 1] == 0)
            {
                q.push({{i, j - 1}, d + 1});
                dist[i][j - 1] = d + 1;
                visit[i][j - 1] = 1;
            }
        }
        q.pop();
    }
    for (auto i : dist)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    // cout << current.first.first << " " << current.first.second << " " << current.second;

    return 0;
}