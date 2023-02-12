#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
      long long findTheArrayConcVal(vector<int> nums)
      {
            long long ans = 0;
            int j = nums.size() - 1;
            int digit;
            for (int i = 0; i < nums.size(); i++)
            {
                  if (i > j)
                  {
                        break;
                  }
                  if (i == j)
                  {
                        ans = ans + nums[i];
                        break;
                  }
                  digit = log10(nums[j]) + 1;
                  ans = ans + ((nums[i] * pow(10, digit)) + nums[j]);
                  j--;
            }
            return ans;
      }
};

int main()
{
      Solution obj;
      cout << obj.findTheArrayConcVal({5, 14, 13, 8, 12});
      return 0;
}
