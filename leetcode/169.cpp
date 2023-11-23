#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int ans2 = 0;
        int index = 0;
        int i;
        for ( i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                ans++;
            }
            else
            {
                if (ans2 < ans)
                {
                    ans2 = ans;
                    index = i;
                }
                ans = 0;
            }
        }
        if (ans2 < ans)
        {
            ans2 = ans;
            index = i;
        }
        return nums[index];
    }
};
int main()
{
    Solution o;
    cout << o.majorityElement({2,2,1,1,1,2,2});

    return 0;
}