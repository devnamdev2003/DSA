#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
      vector<int> twoSum(vector<int> &nums, int target)
      {
            sort(nums.begin(), nums.end());
            int l = 0;
            int r = nums.size() - 1;
            while (l < r)
            {
                  int sum = nums[l] + nums[r];
                  if (sum < target)
                  {
                        l++;
                  }
                  else if (sum > target)
                  {
                        r--;
                  }
                  else
                  {
                        return {l, r};
                  }
            }
            return {};
      }
};

int main()
{
      Solution obj;
      vector<int> nums = {3, 2, 4};
      int target = 6;
      vector<int> ans = obj.twoSum(nums, target);
      for (auto i : ans)
      {
            cout << i << " ";
      }
      return 0;

      return 0;
}