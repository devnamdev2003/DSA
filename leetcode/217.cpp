#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(vector<int> v)
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
      bool containsDuplicate(vector<int> nums)
      {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1; i++)
            {
                  if (nums[i] == nums[i + 1])
                  {
                        return 1;
                  }
            }
            return 0;
      }
};

int main()
{
      Solution obj;
      cout << obj.containsDuplicate({1, 1, 3, 4, 5});

      return 0;
}