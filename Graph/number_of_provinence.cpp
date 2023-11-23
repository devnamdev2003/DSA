#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &visit, int current, vector<int> &store)
{
    visit[current] = 1;
    store.push_back(current);
    for (int i = 0; i < adj[current].size(); i++)
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
    pair<int, int> edge[] = {{1, 2}, {3,4},{3,5},{1,4},{1,3},{5,2}};

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
    int count = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (visit[i] == 0)
        {
            count++;
            dfs(v, visit, i, store);
            for (auto i : store)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    cout << count;
    return 0;
}
