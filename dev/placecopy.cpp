#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include<bits/stdc++.h>


using namespace std;

struct Device
{
    int id;
    vector<pair<int, double>> connections;
};

void addDevice(int id, int numConnections, unordered_map<int, Device> &devices)
{
    devices[id].id = id;
    for (int i = 0; i < numConnections; ++i)
    {
        int connectedId, distance;
        double angle;
        cin >> connectedId >> distance >> angle;
        devices[id].connections.push_back({connectedId, distance});
    }
}

bool dfs(int current, int end, unordered_set<int> &visited, vector<int> &path, unordered_map<int, Device> &devices)
{
    visited.insert(current);
    path.push_back(current);

    if (current == end)
    {
        return true;
    }

    for (const auto &connection : devices[current].connections)
    {
        int nextDevice = connection.first;

        if (visited.find(nextDevice) == visited.end())
        {
            if (dfs(nextDevice, end, visited, path, devices))
            {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

bool findPath(int start, int end, vector<int> &path, unordered_map<int, Device> &devices)
{
    unordered_set<int> visited;
    path.clear();

    return dfs(start, end, visited, path, devices);
}

double calculateTotalDistance(const vector<int> &path, unordered_map<int, Device> &devices)
{
    double totalDistance = 0.0;

    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        int currentDevice = path[i];
        int nextDevice = path[i + 1];

        for (const auto &connection : devices[currentDevice].connections)
        {
            if (connection.first == nextDevice)
            {
                totalDistance += connection.second;
                break;
            }
        }
    }

    return totalDistance;
}

int main()
{
    int N;
    cin >> N;

    unordered_map<int, Device> devices;

    for (int i = 0; i < N; ++i)
    {
        int id, numConnections;
        cin >> id >> numConnections;
        addDevice(id, numConnections, devices);
    }

    int start, end;
    cin >> start >> end;

    vector<int> path;
    bool found = findPath(start, end, path, devices);

    if (found)
    {
        double distance = calculateTotalDistance(path, devices);
        cout << fixed << setprecision(2) << distance;
    }
    else
    {
        cerr << "Path not found!" << endl;
    }

    return 0;
}
