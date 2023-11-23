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
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int point = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] <= nums[i + 1])
            {
                continue;
            }
            else
            {
                point=i + 1 ;
                break;
            }
        }
        cout << "point: " << point << endl;
        reverse(nums.begin() + point, nums.end());
        show_1d(nums);
        reverse(nums.begin(), nums.begin() + point);
        show_1d(nums);

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {10,1,4,5,10};
    cout << obj.check(nums) << endl;
    return 0;
}
