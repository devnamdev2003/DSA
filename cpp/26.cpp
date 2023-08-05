#include <iostream>
#include <vector>
#include <set>
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
    int removeDuplicates(vector<int> nums)
    {
        // set<int> ans(nums.begin(), nums.end());
        // vector<int> ans1(ans.begin(), ans.end());
        // nums.clear();
        // nums = ans1;
        // return ans1.size();
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        show_1d(nums);
        return i + 1;
    }
};
int main()
{
    Solution o;
    cout << o.removeDuplicates({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
    return 0;
}