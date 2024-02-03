#include <bits/stdc++.h>
using namespace std;

void printPath(const vector<int>& path) {
    for (int node : path) {
        cout << node << " -> ";
    }
    cout << endl;
}

int main() {
    int n = 6;
    vector<pair<int, int>> adj[n]{
        {{1, 4}, {2, 14}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{2, 6}, {3, 2}, {4, 3}}
    };

    int start = 0;
    int destination = 5;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    vector<int> dist(n, INT16_MAX);
    vector<int> parent(n, -1);

    minH.push({0, start});
    dist[start] = 0;

    while (minH.size() != 0) {
        auto current = minH.top();
        int d = current.first;
        int node = current.second;

        for (auto i : adj[node]) {
            if (i.second + d < dist[i.first]) {
                minH.push({(i.second + d), i.first});
                dist[i.first] = i.second + d;
                parent[i.first] = node;
            }
        }
        minH.pop();
    }

    cout << "Shortest distance from " << start << " to " << destination << ": " << dist[destination] << endl;

    // Store the path in a vector
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    printPath(path);

    return 0;
}
