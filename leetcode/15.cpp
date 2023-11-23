#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
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
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> v2(s.begin(), s.end());
        return v2;
    }
};
int main()
{
    Solution o;
    show_2d(o.threeSum({-1, 0, 1, 2, -1, -4}));
    return 0;
}