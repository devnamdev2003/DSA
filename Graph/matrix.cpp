#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n = 5, m = 6;
    // ! adjacancy matrix
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    // for (int i = 0; i <= n; i++)
    // {
    //     v[0][i] = i;
    //     v[i][0] = i;
    // }
    pair<int, int> edge[] = {{2, 1}, {1, 3}, {2, 5}, {4, 5}, {3, 4}, {4, 2}};
    for (int i = 0; i < m; i++)
    {
        v[edge[i].first][edge[i].second] = 1;
        v[edge[i].second][edge[i].first] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    // ! adjacancy list
    // vector<vector<int>> v(n + 1);
    // pair<int, int> edge[] = {{2, 1}, {1, 3}, {2, 5}, {4, 5}, {3, 4}, {4, 2}};
    // for (int i = 0; i <= n; i++)
    // {
    //     v[edge[i].first].push_back(edge[i].second);
    //     v[edge[i].second].push_back(edge[i].first);
    // }
    // for (int i = 1; i < v.size(); i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << "->";
    //     }
    //     cout << endl;
    // }

    // ! convert matrix to list
    vector<int> adjlist[n + 1];
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
            {
                adjlist[i].push_back(j);
            }
        }
    }
    for (int i = 1; i < 6; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j] << "->";
        }
        cout << endl;
    }

    return 0;
}