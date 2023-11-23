#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      void moveZeroes(vector<int> nums)
      {
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                  if (nums[i] == 0)
                  {
                        nums.erase(nums.begin() + i);
                        nums.push_back(0);
                        i = 0;
                        n--;
                  }
            }
      }
};
int main()
{
      Solution obj;
      obj.moveZeroes({0, 0, 1});
}