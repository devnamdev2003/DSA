#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
class Solution
{
public:
    vector<int> findDuplicates(vector<int> nums)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution o;
    show_1d(o.findDuplicates({6, 2, 5, 2, 2, 6, 6}));
    return 0;
}