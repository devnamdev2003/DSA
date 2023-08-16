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
class Solution
{
public:
    
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++)
        {
            hash_map[nums[i]] += 1;
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
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};
void show_1d(vector<int> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1)
        {
            cout << v[i] << ",";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << "]";
    cout << endl;
}
int main()
{
    Solution obj;
    vector<int> v = {1, 2, 3, 1, 1, 2, 4, 5, 5};
    vector<int> v2 = obj.topKFrequent(v, 2);
    show_1d(v2);
    return 0;
}