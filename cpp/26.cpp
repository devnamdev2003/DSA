#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> nums)
    {
        set<int> ans(nums.begin(), nums.end());
        vector<int> ans1(ans.begin(), ans.end());
        nums.clear();
        nums = ans1;
        return ans1.size();
    }
};
int main()
{
    Solution o;
    cout << o.removeDuplicates({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
    return 0;
}