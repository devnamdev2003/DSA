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
    int singleNumber(vector<int> &nums)
    {
        int count = 0;
        int d = 0;
        sort(nums.begin(), nums.end());
        show_1d(nums);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[0] != nums[1])
            {
                return nums[0];
            }
            else if (nums[nums.size() - 2] != nums[nums.size() - 1])
            {
                return nums[nums.size() - 1];
            }
            else if (d == 2)
            {
                return nums[i - 1];
            }
            if (nums[i] == nums[i + 1])
            {
                d = 0;
                count++;
            }
            else
            {
                d++;
            }
        }
        return nums[0];
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1};
    cout << obj.singleNumber(nums) << endl;
    return 0;
}