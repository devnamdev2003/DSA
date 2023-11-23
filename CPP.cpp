#include <bits/stdc++.h>
using namespace std;

long long solve(int N, int start, int finish, vector<int> Ticket_cost)
{
    vector<pair<int, int>> adj[N + 1];
    adj[1].push_back({N, Ticket_cost[N - 1]});
    adj[1].push_back({1 + 1, Ticket_cost[0]});

    adj[N].push_back({N - 1, Ticket_cost[N - 2]});
    adj[N].push_back({1, Ticket_cost[N - 1]});
    for (int i = 1; i < N + 1; i++)
    {
        if (i != Ticket_cost[0] && i != Ticket_cost[N - 1])
        {
            adj[i].push_back({i - 1, Ticket_cost[i - 2]});
            adj[i].push_back({i + 1, Ticket_cost[i - 1]});
        }
    }
    for (int i = 0; i < N + 1; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j].first << "(" << adj[i][j].second << ")"
                 << "->";
        }
        cout << endl;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    vector<int> dist(N + 1, INT16_MAX);
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
    return dist[finish];
}

int main()
{

    int N = 10;

    int start = 5;

    int finish = 3;

    vector<int> Ticket_cost = {4, 14, 10, 7, 3, 13, 5, 15, 13, 4};
    int out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}
