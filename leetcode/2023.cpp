#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      int numOfPairs(vector<string> nums, string target)
      {
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                  for (int j = 0; j < nums.size(); j++)
                  {
                        if (nums[i] + nums[j] == target && i != j)
                        {
                              count++;
                        }
                  }
            }
            return count;
      }
};
int main()
{
      Solution obj;
      cout << obj.numOfPairs({"@3", "21"}, "2323");

      return 0;
}