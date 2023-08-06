#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int i = 0;
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums[0] != nums[1])
        {
            return nums[0];
        }
        else if (nums[nums.size() - 1] != nums[nums.size() - 2])
        {
            return nums[nums.size() - 1];
        }
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nums[i] != nums[i + 1] ? count++ : count = 0;
            if (count == 2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 3, 10};
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}