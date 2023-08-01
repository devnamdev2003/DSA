#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1;)
        {
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin() + i + 1);
                continue;
            }
            i++;
        }
        return intervals;
    }
};

void show_2d(vector<vector<int>> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution obj;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    show_2d(obj.merge(intervals));
    return 0;
}