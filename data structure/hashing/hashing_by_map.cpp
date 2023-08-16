#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second > p2.second)
        return true;
    if (p1.second < p2.second)
        return false;
    if (p1.first < p2.first)
        return true;
    return false;
}
int main()
{
    vector<int> v = {11, 2, 3, 1, 1, 2, 4, 5, 5};
    unordered_map<int, int> hash_map;
    for (int i = 0; i < v.size(); i++)
    {
        hash_map[v[i]] += 1;
    }
    pair<int, int> p[hash_map.size()];
    int i = 0;
    for (auto v : hash_map)
    {
        p[i].first = v.first;
        p[i].second = v.second;
        i++;
    }
    sort(p, p + hash_map.size(), comp);
    for (auto v : p)
    {
        cout<<v.first<<" "<<v.second<<endl;
    }
    return 0;
}