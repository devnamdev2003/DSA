#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include<bits/stdc++.h>
#include <unordered_set>

using namespace std;

struct Device
{
    int id;
    vector<pair<int, double>> connections;
};

class PlaceFinder
{
private:
    unordered_map<int, Device> devices;

public:
    void addDevice(int id, int numConnections)
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

    double findDistance(int start, int end)
    {
        vector<int> path;
        bool found = findPath(start, end, path);

        if (!found)
        {
            cerr << "Path not found!" << endl;
            return -1.0;
        }

        double totalDistance = calculateTotalDistance(path);
        return totalDistance;
    }

private:
    bool dfs(int current, int end, unordered_set<int> &visited, vector<int> &path)
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
                if (dfs(nextDevice, end, visited, path))
                {
                    return true;
                }
            }
        }
        path.pop_back();
        return false;
    }
    bool findPath(int start, int end, vector<int> &path)
    {
        unordered_set<int> visited;
        path.clear();

        return dfs(start, end, visited, path);
    }

    double calculateTotalDistance(const vector<int> &path)
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
};

int main()
{
    int N;
    cin >> N;

    PlaceFinder placeFinder;

    for (int i = 0; i < N; ++i)
    {
        int id, numConnections;
        cin >> id >> numConnections;
        placeFinder.addDevice(id, numConnections);
    }

    int start, end;
    cin >> start >> end;

    double distance = placeFinder.findDistance(start, end);

    if (distance >= 0.0)
    {
        cout << fixed << setprecision(2) << distance;
    }

    return 0;
}
