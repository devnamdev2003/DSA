#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &visit, int current, vector<int> &store)
{
    visit[current] = 1;
    store.push_back(current);
    for (int i = 0; i < adj[current].size(); i ++)
    {
        if (visit[adj[current][i]] == 0)  
        {
            dfs(adj, visit, adj[current][i], store);
        }
    }
}

int main()
{
    int n = 5;
    vector<int> v[n + 1];
    pair<int, int> edge[] = {{2, 1}, {1, 3}, {2, 5}, {4, 5}, {3, 4}, {4, 2}};

    for (int i = 0; i < 6; i++)
    {
        v[edge[i].first].push_back(edge[i].second);
        v[edge[i].second].push_back(edge[i].first);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << "->";
        }
        cout << endl;
    }

    vector<int> visit(n + 1, 0);
    vector<int> store;
    dfs(v, visit, 1, store);

    for (auto i : store)
    {
        cout << i << " ";
    }

    return 0;
}
